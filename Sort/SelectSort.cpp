template<typename T>
void SelectSort(T *arr,int len)//ʱ�临�Ӷ�O(n^2) �ռ临�Ӷ�O(1) ,���ȶ�
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
