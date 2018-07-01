template<typename T>
static void Merge(T *arr,int len,int gap)
{
	int low1 = 0 ;
	int high1 = low1+gap-1 ;
	int low2 = high1+1 ;
	int high2 = low2+gap-1 < len-1 ? low2+gap-1 : len-1 ;
	int i = 0 ;
	int *brr = new int[sizeof(int)*len] ;

	while( low2 < len )
	{
		while( low1 <= high1 && low2 <= high2 )
		{ 
			if( arr[low1] <= arr[low2] )
				brr[i++] = arr[low1++] ;

			else
				brr[i++] = arr[low2++] ;
		}

		while( low1 <= high1 )
			brr[i++] = arr[low1++] ;

		while( low2 <= high2 )
			brr[i++] = arr[low2++] ;

		low1 = high2+1 ;
		high1 = low1+gap-1 ;
		low2 = high1+1 ;
		high2 = low2+gap-1 < len-1 ? low2+gap-1 : len-1 ;
	}

	while( low1 < len )
		brr[i++] = arr[low1++] ;

	for( i = 0 ; i < len ; i++ )
		arr[i] = brr[i] ;

	delete[] brr ;
}

template<typename T>
void MergeSort(T *arr,int len)
{
	int i ;

	for( i = 1 ; i < len ; i*= 2 )
		Merge(arr,len,i) ;
}