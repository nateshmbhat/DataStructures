#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct ss
{
	int top  ;
	char items[100] ;

}STACK, S={-1 , {'#'}};

void insert(struct ss * s , int item )
{
	if(s->top == 100){ printf("Overflow !!\n"); return ; }

	s->items[++s->top]  = item ;
}

int pop(struct ss * s)
{
	return s->items[s->top--] ;

}

int preced(char c)
{
	switch(c)
	{
		case '(':
		case '#' : return 0 ;
		case '+' :
		case '-' :return 1 ;
		case '*' :
		case '%' :
		case '/' :return 2 ;
		case '^' :
		case '$' : return 3 ;
	}
}


void main()
{
	char infix[100] , postfix[100] ;
	gets(infix) ;
	int p=0, i , n ,j  ; char  symb;
	char c ;


	for(i=0 ; infix[i] ; i++)
	{
		symb = infix[i] ;
		if(isalnum(symb)) {postfix[p++] = symb ; continue ;}
		if(symb=='(')insert(&S , '(') ;

		else if(symb==')')
		{
			while((c = pop(&S))!='(')
			{
				postfix[p++] = c ;
			}
		}


		else
		{
			while(preced(symb) <= preced(S.items[S.top]))
				postfix[p++] = pop(&S);
			insert(&S , symb) ;
		}


	}

	while(S.items[S.top]!='#')
		postfix[p++] = pop(&S) ;
	postfix[p] = 0 ;

	puts(postfix) ;

}
