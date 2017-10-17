#include<stdio.h>
#include <stdlib.h>

void sort(int a[] ,int  n) ;
void merge(int a[] , int n , int left[] , int j , int right[] , int k);



int main()
{
	int i,a[100] ,n ;
	printf("Enter n : ") ;
	scanf("%d", &n) ;
	for(i=0 ; i< n ; i++) scanf("%d", &a[i]) ;

	sort(a , n) ;	
	for(i=0 ; i<n ; i++) printf("%d " , a[i]) ;
}

void sort(int a[] , int n)
{
	int mid = n/2 , i=0 , k=0 , j=0 , left[100] , right[100] ; 

	for(i=0 ; i< mid ; i++)left[j++] = a[i] ;
	for(i=mid ; i<n ; i++) right[k++] = a[i] ;

	if(n==1 || n==0) return ;
	sort(left , j) ;
	sort(right  , k) ;
	merge(a , n ,left , j , right , k) ;
}

void merge(int a[] , int n ,int left[] , int j , int right[] , int k)
{
	int i =0 , lc =0 , rc = 0;
	while(lc<j && rc<k)
	{
		// left[i]>right[i]?a[i] = left[i],lc++ : a[i]= right[i] ;
		a[i] = left[lc]<right[rc]?left[lc++] : right[rc++] ;
		i++ ; 
	}

	while(rc<k) a[i] = right[rc++] , i++ ;
	while(lc<j) a[i] = left[lc++] , i++ ;
}

/// 4 7    3 8


