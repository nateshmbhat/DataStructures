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




void reverse_list(node * child , node * parent )
{
    if(child->next  == 0) 
    {
        printf("%d -> " , child->data) ; 
        child->next= parent ; 
        return ; 
    }
    
    parent = parent->next; 
    child = child->next ;
    reverse_list(child , parent ) ;

    child->next = parent ; 
    printf("%d ->" , parent->data) ;
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

    node * first = head->next ; 

    printf("\n\n") ; 

    reverse_list(first->next , first)  ;
}