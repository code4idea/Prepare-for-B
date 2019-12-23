#include <cstdio>
#include <cstring>

class Trie
{
private:
	Trie* child[30];
	bool finish;

public:
	Trie()
	{
		for(int i=0;i<30;i++) child[i] = NULL;
		finish = false;
	}

	void insert(char* key)
	{
		if(*key == '\0')
		{
			this->finish = true;
			return;
		}
		else
		{
			int index = *key - 'a';
			if(child[index] == NULL)
				child[index] = new Trie();
			child[index]->insert(key+1);
		}
	}

	bool find(char* key)
	{
		if(*key == '\0')
		{
			return true;
		}
		else
		{
			int index = *key - 'a';
			if(child[index] == NULL)
				return false;
			child[index]->find(key+1);
		}
	}

	bool string_exist(char* key)
	{
		if(*key == '\0')
		{
			if(finish == true)
			{
				return true;
			}
			return false;
		}

		int index = *key - 'a';
		if(child[index] == NULL)
			return false;
		return child[index]->string_exist(key+1);
	
	}
};

int main() {

	Trie * root = new Trie();

	char * words[5] = { "be", "bee", "can", "cat", "cd" };

	for (int i = 0; i < 5; ++i) {
		printf("insert : %s\n", words[i]);
		root->insert(words[i]);
	}

	printf("\n");

	printf("%s : be\n", root->find("be") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : can\n", root->find("can") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : a\n", root->find("a") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : cat\n", root->find("cat") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : c\n", root->find("c") != 0 ? "Prefix Exist" : "Prefix Not Exist");

	printf("\n");

	printf("%s : c\n", root->string_exist("c") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : be\n", root->string_exist("be") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : bee\n", root->string_exist("bee") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : candy\n", root->string_exist("candy") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : cd\n", root->string_exist("cd") != 0 ? "String Exist" : "String Not Exist");
	
	delete root;

	return 0;
}
