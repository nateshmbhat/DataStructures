#include<stdio.h>
#include<stdlib.h>

void insert(int q[] , int item)
{	
	if(q[1]==99){printf("Overflow !\n");return ;}
	if(q[0]==1) q[0] = 2 ;
	q[++q[1]] = item ;
}

void delete(int q[])
{
	if(q[0]==1){ printf("Underflow !\n"); return; }
	int item = q[q[0]];
	if(q[0]==q[1]) q[0] = q[1] = 1 ;
	else q[0]++ ;
	return item ;
}

void display(int q[])
{
	int i ;
		for(i=q[0] ; i<=q[1] ; i++)
	{
		printf("%d \n", q[i]);
	}	
}

int main(void)
{
	int n  ,i , q[100] ; 
	q[0] = q[1] = 1   ; //Initialize 
	insert(q , 10) ;
	insert(q , 20) ; 
	printf("\nContents of Queue are : \n ") ; 
	display(q) ;
	delete(q) ; 
	printf("\nContents of Queue are : \n ") ; 
	display(q) ;
}