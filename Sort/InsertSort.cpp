template<typename T>
void InsertSort(T *arr,int len)//ʱ�䣺O(n^2) �ռ䣺O(1) ���ȶ���Խ����Խ�죬��ȫ����ʱ�临�ӶȿɴﵽO(n)
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