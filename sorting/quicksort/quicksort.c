#include<stdio.h>
#include<stdlib.h>

void quicksort(int a[] , int n)
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