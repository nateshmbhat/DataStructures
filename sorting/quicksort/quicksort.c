#include<stdio.h>
#include<stdlib.h>

void quicksort(int a[] , int start , int end)
{
	int pindex = partition(a ,start  ,end); 
	quicksort(int a[] , start , pindex-1) ;
	quicksort(int a[] , pindex , end) ;
}

int partition(int a[] , int start , int end)
{
	
}


int main()
{
	printf("Enter n : ") ; 
	int n, i    ; 
	scanf("%d" , &n) ;

	int *a = (int *)malloc(n*sizeof(int)) ;

	for(i=0 ; i<n ; i++) scanf("%d" , &a[i]);

	quicksort(a , n) ;
}	