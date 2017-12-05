#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int top ; 
	int items[100]  ; 
}STACK ;

STACK reverse(STACK s)
{
	if(s.top==-1)
		return ; 
	int bot = 0 ;
	int top = s.top ;
	int temp ; 
	for(; bot<top ; bot++ , top--)
	{
		temp = s.items[bot] ; 
		s.items[bot] = s.items[top] ; 
		s.items[top] = temp ; 
	}

	return s ;

}

void display(STACK s)
{
	if(s.top==-1)
		return ; 
	int i =0 ; 
	for(i =0 ; i<=s.top ; i++)
		printf("%d -> " , s.items[i]) ; 
}

int main(void)
{
	STACK s={-1 , 0 } ; 
	s.items[++s.top] = 1 ;
	s.items[++s.top] = 2 ; 
	s.items[++s.top] = 3 ;
	s.items[++s.top] = 4 ;
	s.items[++s.top] = 5 ;
	s.items[++s.top] = 6 ;

	printf("Before reversing : ") ; 	
	display(s) ; 
	s = reverse(s) ; 
	printf("\n\nAfter reversing : ") ; 
	display(s) ; 

}
		
