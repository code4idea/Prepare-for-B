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

void quick_sort(int *data, int start, int end)
{
	if (start >= end) return;

	int pivot = start;
	int left = pivot + 1;
	int right = end;

	while (left <= right)
	{
		while (left <= end && data[left] <= data[pivot])
			left++;
		while (right > start && data[right] >= data[pivot])
			right--;

		if (left <= right)
		{
			_swap(data, left, right);
		}
		else
		{
			_swap(data, pivot, right);
		}
	}

	quick_sort(data, start, right - 1);
	quick_sort(data, right+1,end);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int data[30];

	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < 30 ; i++)
	{
		data[i] = rand()%100;
	}

	printt(data);

	quick_sort(data, 0, 29); // 결과 확인

	printt(data);
	return 0;
}
