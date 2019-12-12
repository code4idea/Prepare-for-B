#include <iostream>

using namespace std;

int N, M;
int parent[201], rrank[201];

int find(int x)
{
	if (x == parent[x]) return x;

	return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (rrank[x] < rrank[y]) parent[x] = y;
	else parent[y] = x;
	if (rrank[x] == rrank[y]) rrank[x]++;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < 201; i++)
	{
		rrank[i] = 0;
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 1)
			{
				Union(i, j);
			}
		}
	}
	int res;
	int tmp;
	bool check = true;
	cin >> tmp;
	res = find(tmp);
	for (int i = 0; i < M - 1; i++)
	{
		int tt;
		cin >> tmp;
		tt = find(tmp);
		if (tt != res)
		{
			check = false;
			break;
		}
	}

	if (check == false) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}
