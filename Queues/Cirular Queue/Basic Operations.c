#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define max 4

typedef struct queue
{
    int r , f ; 
    int items[100] ; 
}queue ; 


int Delete(queue * q)
{
    int data = q->items[q->f] ;
    if(q->f==-1)
    {
        printf("Underflow ! \n") ;
        return -1 ;
    }
    if(q->f==q->r)
        {
            q->f = q->r = -1 ;
            return data ; 
        }

    q->f = (q->f+1) %max ;
    return data ; 
}


void Insert(queue * q , int data)
{
    if((q->f==0 && q->r==max-1) || (q->f==q->r+1))
        {printf("OVERFLOW ! \n") ; return ; }
    q->r = (q->r+1)%max  ;
    
    q->items[q->r] = data ;
    if(q->f==-1) q->f=0 ; 

}

void display(queue q)
{
    if(q.f==-1) return ;
    for(int i =q.f ; i!=q.r ; i = (i+1)%max)
        printf("%d " , q.items[i]) ;
    printf("%d " , q.items[q.r]) ;
    printf("\n") ;
}

int main()
{
    queue q={-1 , -1} ; 

    for(int i = 0 ; i< 5 ; i++)
    {
        Insert(&q , i) ; 
        display(q) ; 
    }

    Delete(&q) ; 
    Delete(&q) ;
    display(q);
    Insert(&q , 4);
    Insert(&q , 5);
    display(q) ; 

    printf("\n\n") ;
    for(int i = 0 ; i< 5 ; i++)
    {
        Delete(&q ) ; 
        display(q) ; 
    }


    
}