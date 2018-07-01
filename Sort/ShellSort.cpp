template<typename T>
static void Gap_InsertSort(T *arr,int len,int gap)
{
	int i ;
	int j ;
	int tmp ;

	for( i = gap ; i < len ; i++ )
	{
		tmp = arr[i] ;

		for( j = i-gap ; j >= 0 ; j -= gap )
		{
			if( arr[j] > tmp )
				arr[j+gap] = arr[j] ;

			else
				break ;
		}
		arr[j+gap] = tmp ;
	}
}

template<typename T>
void ShellSort(T *arr,int len)
{
	int d[] = {/*50000257,10000339,8003089,*//*4000567,1002077,701227,304049,141937,*/21881,11971,8969,5507,3001,911,373,59,17,7,1} ;
	/*int d[] = {304049,141937,21881,8969,3001,911,59,17,7,1};*/

	int i ;

	for( i = 0 ; i < sizeof(d)/sizeof(d[0]) ; i++ )
	{
		Gap_InsertSort(arr,len,d[i]) ;
	}
}