#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data ; 
    struct node * next ;
}node ;


///If the position is 0 insert at first  , else if pos = -1 insert at end , else insert at given position 
void  insert_node( node * head , int data , int pos )
{
    node * newnode = (node * )malloc(sizeof(node)) ; 
    newnode->data = data ;

     

    switch(pos)
    {
        case 0:
            newnode->next = head->next ; 
            head->next  = newnode ; 
            break ; 

        case -1:

            node * temp ;
            for(temp = head->next ; temp && temp->next  ; temp=temp->next ) ;
            //Temp now points to last node ;

            temp->next = newnode ;
            newnode->next  = NULL ;
        
        default:
            node * temp , *parent = head ;
            temp = head->next ;

            int i = 0 ; 
            for(i =1 ; temp && i<=pos  ; i++)
                {
                    parent = temp ; 
                    temp = temp->next ; 
                }

            if(i!=pos)
            {
                printf("Invalid position ! ") ;
                return ;
            }
            parent->next = newnode ;
            newnode->next = temp ;

    }

    head->data++ ;
}


void reverse_list(node * first)
{
    if(first == 0) return ; 

    reverse_list(first->next ) ;
    printf("%d ->" , first->info) ;
}


int main()