#include<stdio.h>
#include<stdlib.h>


typedef struct ss
{
	int top  ;
	char items[100] ;
	
}STACK ; 

void insert(STACK *s , int item )	
{
	if(s->top == 100){ printf("Overflow !!\n"); return ; } 

	s->items[++s->top]  = item ;
}

int pop(STACK* s)
{
	return s->items[s->top--] ;
}


void transfer(STACK *s1 , STACK *s2 , STACK *s3)
{
    int i = 0 ;
    int top = s1->top; 
    for(i=0 ; i<=top ; i++)
        insert(s2 , pop(s1)) ;
    
    for(i =0 ; i<=top ; i++)
        insert(s3 , pop(s2)) ;
}


void display(STACK s)
{
    int i = 0 ; 
    printf("\n") ; 
    for(i = 0 ; i<=s.top ; i++)
        printf("%c " , s.items[i]) ;
}


int main(void)
{

    STACK s1 = {-1} , s2 = {-1} , s3={-1} ;
    insert(&s1 , 'a') ;
    insert(&s1 , 'b') ;
    insert(&s1 , 'c') ;
    insert(&s1 , 'd') ;

    display(s1) ; 
    transfer(&s1 , &s2 , &s3) ; 
    display(s3) ;

}