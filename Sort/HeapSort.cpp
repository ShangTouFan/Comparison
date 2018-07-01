template<typename T>
static void HeapAdjust(T *arr,int start,int end)
{
	int tmp = arr[start] ;
	int i ;
	int parent = start ;

	for( i = start*2+1 ; i <= end ; i = i*2+1 )
	{
		if( i+1 <= end && arr[i] < arr[i+1] )
			i++ ;

		if(arr[i] > tmp )
		{
				arr[parent] = arr[i] ;
				parent = i ;
		}

		else
			break ;
	}

	arr[parent] = tmp ;
}

template<typename T>
void HeapSort(T *arr,int len)//时间O(nlogn),空间O(1),不稳定
{
	int i ;

	for( i = (len-2)/2 ; i >= 0 ; i-- )
		HeapAdjust(arr,i,len-1) ;

	int tmp ;

	for( i = len-1 ; i > 0 ; i-- )
	{
		tmp = arr[0] ;
		arr[0] = arr[i] ;
		arr[i] = tmp ;

		HeapAdjust(arr,0,i-1) ;
	}

}