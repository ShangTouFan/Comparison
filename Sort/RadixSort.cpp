template<typename T>
static int GetMaxCount(T *arr,int len)
{
	int i ;
	int tmp ;
	int index_max = 0 ;
	int count = 0 ;

	for( int i = 1 ; i < len ; i++ )
	{
		if( arr[index_max] < arr[i] )
			index_max = i ;
	}

	tmp = arr[index_max] ;

	while( tmp )
	{
		tmp /= 10 ;
		count++ ;
	}

	return count ;
}

template<typename T>
static void Radix(T *arr,int len,int figures)
{
	int i ;
	int j ;
	int count = 0 ;
	int unit ;
	int tmp ;
	int rtval ;
	QHead Figure[10] ;

	for( i = 0 ; i < 10 ; i++ )
		InitQueue(&Figure[i]) ;

	for( i = 0 ; i < len ; i++ )
	{
		tmp = arr[i] ;

		while( count < figures )
		{
			unit = tmp % 10 ;
			tmp /= 10 ;
			count++ ;
		}

		count = 0 ;
		Push(&Figure[unit],arr[i]) ;
	}

	j = 0 ;

	for( i = 0 ; i < len ;  )
	{
		if( Pop(&Figure[j],&arr[i]) )
			i++ ;

		else
			j++ ;
	}
	
	for( i = 0 ; i < 10 ; i++ )
		Destroy(&Figure[i]) ;
}

template<typename T>
void RadixSort(T *arr,int len)
{
	int count = GetMaxCount(arr,len) ;

	for( int i = 1 ; i <= count ; i++ )
		Radix(arr,len,i) ;
}