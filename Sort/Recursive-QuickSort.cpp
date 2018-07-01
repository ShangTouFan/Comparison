template<typename T>
void Recursive_QuickSort(T *arr,int low,int high)
{
	if(low >= high)
		return ;
	int first = low ;
	int last = high ;
	int key = arr[low];
	while(first < last)
	{
		while(first < last && key <= arr[last])
			last--;
		arr[first] = arr[last];
		while(first < last && key >= arr[first])
			first++;
		arr[last] = arr[first];
	}
	arr[first] = key ;
	Recursive_QuickSort(arr,low,first-1);
	Recursive_QuickSort(arr,first+1,high);
}