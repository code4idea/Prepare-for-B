#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
};


template <typename T>
class BST
{
private:
	Node<T>* root = new Node<T>();

public:
	BST()
	{

	}

	void insert(T data)
	{
		if (root->data == NULL)
		{
			root->data = data;
		}
		else
		{
			Node<T>* cur;
			cur = root;
			while (1)
			{
				if (data > cur->data)
				{
					if (cur->right == NULL)
					{
						Node<T>* tmp = new Node<T>();
						tmp->data = data;
						cur->right = tmp;
						cur->right->parent = cur;
						break;
					}
					else
						cur = cur->right;
				}
				else
				{
					if (cur->left == NULL)
					{
						Node<T>* tmp = new Node<T>();
						tmp->data = data;
						cur->left = tmp;
						cur->left->parent = cur;
						break;
					}
					else
						cur = cur->left;
				}
			}
		}
	}

	bool find(T data)
	{
		Node<T>* cur;
		cur = root;
		while (1)
		{
			if (data > cur->data)
			{
				if (cur == NULL) return false;
				cur = cur->right;
			}
			else if (data < cur->data)
			{
				if (cur == NULL) return false;
				cur = cur->left;
			}
			else
				return true;
		}
	}

	T remove(T data)
	{
		if (root == NULL) return -1;

		Node<T>* cur;
		cur = root;
		if (cur == NULL)
		{
			cout << "EMPTY" << endl;
			return -1;
		}

		while (1)
		{
			if (data > cur->data)
			{
				
				cur = cur->right;
			}
			else if (data < cur->data)
			{
				cur = cur->left;
			}
			else
				break;
		}

		if (cur->left == NULL && cur->right == NULL)
		{
			T res = cur->data;
			if (cur->parent == NULL) root = NULL;
			else
			{
				if (cur->parent->left == cur) cur->parent->left = NULL;
				else cur->parent->right = NULL;
			}

			return res;
		}
		else if (cur->left == NULL || cur->right == NULL)
		{
			T res = cur->data;
			if (cur->left == NULL)
			{
				cur->right = cur;
			}
			else
			{
				cur->left = cur;
			}

			return res;
		}
		else
		{
			T res = cur->data;
			Node<T>* tmp;
			tmp = cur->right;
			if (tmp->left == NULL)
			{
				if (tmp->right != NULL)
				{
					tmp->parent->right = tmp->right;
					cur->data = tmp->data;
					tmp = NULL;
				}
				else {
					cur->data = tmp->data;
					tmp->parent->right = NULL;
					tmp = NULL;
				}
			}
			else
			{
				while (tmp->left != NULL)
				{
					tmp = tmp->left;
				}

				if (tmp->right != NULL)
				{
					tmp->parent->left = tmp->right;
					cur->data = tmp->data;
					tmp = NULL;
				}
				else {
					cur->data = tmp->data;
					tmp->parent->left = NULL;
					tmp = NULL;
				}
			}
		
			return res;
		}
	}

	Node<T>* getroot()
	{
		return root;
	}

	void levelOrder(BST<T> t, Node<T>* node)
	{
		if (node == NULL) return;
		cout << node->data << endl;
		levelOrder(t, node->left);
		levelOrder(t, node->right);
	}
};

int main(void)
{
	BST<int> b = BST<int>();

	b.insert(35);
	b.insert(18);
	b.insert(7);
	b.insert(26);
	b.insert(12);
	b.insert(3);
	b.insert(68);
	b.insert(22);
	b.insert(24);
	b.insert(30);
	b.insert(99);
	b.levelOrder(b, b.getroot());

	cout << " ajdkj " << b.remove(18) << endl;

	b.levelOrder(b, b.getroot());
	return 0;
}
