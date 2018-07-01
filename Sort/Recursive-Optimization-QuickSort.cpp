template<typename T>
static int GetLow(T *arr,int low,int high)
{
	int mid = low+( ( high - low ) >>1 ) ;

	if( arr[mid] > arr[high] )
	swap(arr[mid],arr[high]);

	if( arr[mid] > arr[low] )
	swap(arr[mid],arr[low]);

	if( arr[low] > arr[high] )
	swap(arr[low],arr[high]);

	return arr[low] ;
}

template<typename T>
static int Partition(T *arr,int low,int high,int *leftlen,int *rightlen)
{
	int chtmp ;
	int tmp ;
	int first = low ;
	int last = high ;
	int left = low ; 
	int right = high ;
	*leftlen = 0 ;
	*rightlen = 0 ;
	tmp = GetLow(arr,low,high) ;

	while( low < high )
	{
		while( low < high && tmp <= arr[high] )
		{
			if( tmp == arr[high] )
			{
				chtmp = arr[high] ;
				arr[high] = arr[right] ;
				arr[right] = chtmp ;
				++(*rightlen) ;
				right-- ;
			}
			high-- ;
		}

		arr[low] = arr[high] ;

		while( low < high && tmp >= arr[low] )
		{
			if( tmp == arr[low] )
			{
				chtmp = arr[low] ;
				arr[low] = arr[left] ;
				arr[left] = chtmp ;
				++(*leftlen) ;
				left++ ;
			}
			low++ ;
		}

		arr[high] = arr[low] ;
	}

	arr[low] = tmp ;

	int i = first ;
	int j = low - 1 ;

	while( i < left && arr[j] != tmp )
	{
		chtmp = arr[i] ;
		arr[i] = arr[j] ;
		arr[j] = chtmp ;
		i++ ;
		j-- ;
	}

	i = last ;
	j = high+1 ;

	while( i > right && arr[j] != tmp )
	{
		chtmp = arr[i] ;
		arr[i] = arr[j] ;
		arr[j] = chtmp ;
		i-- ;
		j++ ;
	}

	return low ;
}

template<typename T>
static void Quick(T *arr,int low,int high)
{
	if(low >= high)
		return ;

	if(high-low < 20)
	{
		InsertSort(arr+low,high-low+1);
		return ;
	}

	int leftlen ;
	int rightlen ;
	int parlow = Partition(arr,low,high,&leftlen,&rightlen) ;
	
	if( parlow-1-leftlen > low )
			Quick(arr,low,parlow-1-leftlen) ;
	 
	if( parlow +1+rightlen < high )
			Quick(arr,parlow+1+rightlen,high) ;

}

template<typename T>
void Rec_Opt_QuickSort(T *arr,int len)
{
	Quick(arr,0,len-1) ;
}