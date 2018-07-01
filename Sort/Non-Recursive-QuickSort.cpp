template<typename T>
int Non_Recursive_Partition(T *arr,int low,int high)
{
	int key = arr[low];
	while(low < high)
	{
		while(low < high && key <= arr[high])
			high--;
		arr[low] = arr[high];
		while(low < high && key >= arr[low])
			low++;
		arr[high] = arr[low];
	}
	arr[low] = key ;
	return low ;
}

template<typename T>
void Non_Recursive_QuickSort(T *arr,int low,int high)
{
	if(low >= high)
		return ;
	stack<int> s;
	s.push(low);
	s.push(high);
	while(!s.empty())
	{
		int j = s.top();
		s.pop();
		int i = s.top();
		s.pop();
		int k = Non_Recursive_Partition(arr,i,j);
		if(k-1>i)
		{
			s.push(i);
			s.push(k-1);
		}
		if(k+1<j)
		{
			s.push(k+1);
			s.push(j);
		}
	}
}