template<typename T>
void SelectSort(T *arr,int len)//时间复杂度O(n^2) 空间复杂度O(1) ,不稳定
{
	int i ;
	int j ;
	int tmp ;
	int min_index ;

	for( i = 0 ; i < len-1 ; i++ )
	{
		min_index = i ;

		for( j = i+1 ; j < len ; j++ )
		{
			if( arr[j] < arr[min_index] )
			{
				min_index = j ;
			}
		}
		
		if( min_index != i )
		{
			tmp = arr[i] ;
			arr[i] = arr[min_index] ;
			arr[min_index] = tmp ;
		}
	}
}
