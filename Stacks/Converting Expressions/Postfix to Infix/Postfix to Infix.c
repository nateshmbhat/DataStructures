#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct ss
{
	int top  ;
	char items[100][100] ;
	
}stack ;


void push(stack * s , char * str)	
{
	if(s->top == 100){ printf("Overflow !!\n"); return ; } 

	strcpy(s->items[++s->top]  ,  str) ;
}


char * pop(struct ss * s)
{
	return s->items[s->top--] ;
}

int main()
{
    printf("Enter posfix : ") ; 
    char op1[20] , op2[20]  , postfix[20] , ch ; 
    char infix[20] ; 
    char op[2] ;
    stack s= {-1} ; 
    int i = 0; 
    scanf("%s" , postfix) ; 

    for(i =0 ; postfix[i]  ;i++)
    {
        ch = postfix[i] ; 
        op[0] = ch ; op[1] = 0 ;
        if(isalnum(ch))
        {
           push(&s , op) ;
        }
        else
        {
            strcpy(infix , "(")  ;
            strcpy(op2 , pop(&s)) ; 
            strcpy(op1 , pop(&s)) ; 
            strcat(infix , op1) ; strcat (infix , op) ; strcat(infix , op2) ; 
            strcat(infix , ")") ;
            push(&s , infix) ;
            
        }
    }

    strcpy(op1 , pop(&s)) ; 
    printf("Result = %s" , op1) ;
}