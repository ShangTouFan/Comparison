template<typename T>
void InsertSort(T *arr,int len)//时间：O(n^2) 空间：O(1) ，稳定，越有序越快，完全有序时间复杂度可达到O(n)
{
	int i ;
	int j  ;
	int tmp ;
	for( i = 1 ; i < len ; i++ )
	{
		tmp = arr[i] ;
		for( j = i-1 ; j >= 0 ; j-- )
		{
			if( arr[j] > tmp )
				arr[j+1] = arr[j] ;

			else
				break ;
		}
		arr[j+1] = tmp ;
	}
}