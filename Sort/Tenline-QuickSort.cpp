template<typename T>
void Tenline_QuickSort(T *arr,int low,int high)
{
    if(low >= high) return ;
    int i = low ;
    for(int j = low ; j < high ; ++j)
        if(arr[j] <= arr[high])
	    swap(arr[j],arr[i++]);
    swap(arr[i],arr[high]);
    Tenline_QuickSort(arr,low,i-1);
    Tenline_QuickSort(arr,i+1,high);
}
