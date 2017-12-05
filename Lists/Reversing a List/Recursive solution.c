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
    node * temp ; 

     

    switch(pos)
    {
        case 0:
            newnode->next = head->next ; 
            head->next  = newnode ; 
            break ; 

        case -1:
            ;

            for(temp = head; temp && temp->next  ; temp=temp->next ) ;
            //Temp now points to last node ;

            temp->next = newnode ;
            newnode->next  = NULL ;
            break ; 
        
        default:
            ; 
            node  *parent = head ;
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



void reverse_list(node * head)
{
    node * first = head->next , *temp , *rev = 0 ;

    while(first!=NULL)
    {
        temp = first ;
        head->next = temp ;
        first = first->next ; 
        temp->next = rev ;
        rev = temp ;
    }
    
}


void display(node * first)
{

    if(!first) return  ; 
    printf("\n") ; 
    node * temp  = first ; 

    for(temp = first ; temp  ; temp= temp->next )    
        printf("%d " , temp->data) ;

}



int main()
{
    node * head = (node *)malloc(sizeof(node)) ;
    head->data  = head->next = 0 ;
    insert_node(head , 1 , -1) ; 
    insert_node(head , 2 , -1) ; 
    insert_node(head , 3 , -1) ; 
    insert_node(head , 4 , -1) ; 
    insert_node(head , 5 , -1) ; 
    insert_node(head , 6 , -1) ; 


    printf("\n\n") ; 

    reverse_list(head)  ;
    display(head->next) ; 
}