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

void counting_sort(int *data, int start, int end)
{
	int Count[101];
	for (int i = 0; i < 101; i++) Count[i] = 0;
	for (int i = 0; i < 30; i++) Count[data[i]]++;

	for (int i = 1; i < 101; i++)
	{
		Count[i] += Count[i - 1];
	}

	int sort[31];
	for (int i = 0; i < 31; i++) sort[i] = 0; // 배열초기화
	for (int i = 0; i < 30; i++)
	{
		int index = Count[data[i]];
		sort[index] = data[i];
		Count[data[i]]--;
	}

	for (int i = 0; i < 30; i++)
	{
		data[i] = sort[i];
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

	counting_sort(data, 0, 29); // 결과 확인

	printt(data);
	return 0;
}
