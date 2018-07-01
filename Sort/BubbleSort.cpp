template<typename T>
void BubbleSort(T *arr,int len)//时间：O(n^2) 空间：O(1)，稳定
{
	int i ;
	int j ;
	int tmp ;

	for( i = 0 ; i < len-1 ; i++ )
	{
		for( j = 0 ; j < len-1-i ; j++ )
		{
			if( arr[j] > arr[j+1] )
			{
				tmp = arr[j] ;
				arr[j] = arr[j+1] ;
				arr[j+1] = tmp ;
			}
		}
	}
}