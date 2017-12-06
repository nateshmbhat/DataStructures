#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


typedef struct STACK
{
    float items[100] ; 
    int top ; 
}stack ; 


void push(stack * s , float data)
{
    s->items[++s->top]  = data ; 
}

float pop(stack * s)
{
    return s->items[s->top--] ; 
}

float  calculate(float op1 , char op , float op2) 
{
    switch(op)    
    {
        case '+' : return op1+op2 ; 
        case '-' : return op1-op2 ; 
        case '*' : return op1*op2 ; 
        case '/' : return op1/op2 ; 
        case '$' : 
        case '^' : return pow(op1,op2) ; 
    }
}


int main()
{
    printf("Enter prefix : ") ; 
    char prefix[20]  , ch ;
    stack s ; 
    s.top = -1 ;   
    scanf("%s" , prefix) ; 
    float op1 , op2  , res ; 
    int i = 0 ; 


    for(i=strlen(prefix)-1 ; i>=0 ; i--)
    {
        ch = prefix[i] ; 

        if(isalnum(ch))
        {
            push(&s , ch-'0') ; 
        } 

        else
        {
            op1 = pop(&s) ; op2 = pop(&s) ; 
            res = calculate(op1 , ch , op2) ; 
            push(&s , res) ; 
        }
    }

    printf("Result : %f" , pop(&s)) ;

}