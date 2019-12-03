 //퀵, 병합 정렬 코딩
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

void merge(int *data, int start, int end)
{
	int tmp_data[30];
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;
	int k = start;

	while (left <= mid && right <= end)
	{
		if (data[left] <= data[right]) tmp_data[k++] = data[left++];
		else tmp_data[k++] = data[right++];
	}

	int tmp = left <= mid ? left : right;

	while (k <= end) tmp_data[k++] = data[tmp++];

	for (int i = start; i <= end; i++)
	{
		data[i] = tmp_data[i];
	}
}

void merge_sort(int *data, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		merge_sort(data, start, mid);
		merge_sort(data, mid+1, end);
		merge(data, start, end);
	}
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

	merge_sort(data, 0, 29); // 결과 확인

	printt(data);
	return 0;
}
