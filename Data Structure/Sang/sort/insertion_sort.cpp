#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void printt(int *data)
{
	for (int i = 0; i < 30; i++)
	{
		printf("%d ", data[i]);
	}
	cout << endl;
}

void _swap(int *data, int start, int end)
{
	int tmp = data[start];
	data[start] = data[end];
	data[end] = tmp;
}

void insertion_sort(int *data, int start, int end)
{
	for (int i = 1; i <= end; i++)
	{
		int tmp = data[i];
		int j = 0;
		for (j = i - 1; j >= 0; j--)
		{
			if (data[j] > tmp)
			{
				data[j+1] = data[j];
			}
			else break;
		}
		data[j+1] = tmp;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int data[30];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 30; i++)
	{
		data[i] = rand() % 100;
	}

	printt(data);

	insertion_sort(data, 0, 29); // 결과 확인

	printt(data);
	return 0;
}
