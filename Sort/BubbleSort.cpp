template<typename T>
void BubbleSort(T *arr,int len)//ʱ�䣺O(n^2) �ռ䣺O(1)���ȶ�
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