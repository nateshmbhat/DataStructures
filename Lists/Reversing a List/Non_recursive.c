#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data ; 
    struct node * next ;
}node ;


///If the position is 0 insert at first  , else if pos = -1 insert at end , else insert at given position 
node * insert_node( node * head , int data , int pos )
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

            

    }
}



int main()