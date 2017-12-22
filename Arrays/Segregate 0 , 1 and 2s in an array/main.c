#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>


void swap(int *a , int i1 , int i2)
{
    int temp = a[i1] ; 
    a[i1] = a[i2] ; 
    a[i2] = temp ; 

}

int main(void)
{
    int n ; 
    printf("Enter n : ") ; int a[100] ; 
    scanf("%d", &n) ; 

    int i = 0 ; 

    printf("Enter %d elements containing only 0 , 1 or 2 : " , n) ; 

    for(i = 0 ; i< n ; i++)
        scanf("%d" , &a[i]) ; 
    if(a[i]>2 && a[i]<0)
        printf("Invalid Input ! ")  , exit(0) ;


    int low = 0 , mid = 1  , high = n-1 ; 

    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a , mid , low) ;
            low++ ; 
            mid++ ; 
        }

        else if(a[mid]==2)
        {
            swap(a , mid , high) ; 
            high-- ;
        }

        else mid++ ;
        
    }

    puts("") ; 
    for(i=0  ; i<n ; i++)
        printf("%d " , a[i]) ;

}

// 1 0 1 0 2 0 1 2 2 0 1 1 2 0