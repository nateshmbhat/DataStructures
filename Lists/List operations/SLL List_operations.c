#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data ; 
    struct node * next ;
} node ; 


node * insert_first(node * first , int data)
{
    node * newnode = (node * )malloc(sizeof(node)) ; 
    newnode->data = data ; 

    newnode->next = first ;
    return newnode ;
}

node * insert_last(node * first , int data)
{
    node * newnode = (node * )malloc(sizeof(node)) ; 
    newnode->data = data ; 
    newnode->next = 0 ; 

    node * temp = first ; 
    if(first == 0 )return newnode ;
    for( ; temp->next ; temp = temp->next) ;

    temp->next = newnode ;

    return first ; 
}


node * delete_last(node * first)
{
    if(!first) return first ; 
    node * temp = first  , * parent = 0 ; 
    while(temp->next)
    {
        parent = temp ; 
        temp = temp -> next ;
    }

    if(parent !=0) 
        parent->next = 0 ; 
    free(temp) ; 
}

node * delete_first(node * first)
{
    if(!first) return ; 
    node *temp = first ; 
    first = first->next ; 
    free(temp) ; 
    return first ; 
}



node * delete_key(node * first , int key )
{
    if(!first) return 0 ; 
    node * temp  = first  , *parent = 0 ;  

    while(temp && temp->data!=key)
    {
        parent  =temp ; 
        temp = temp->next; 
    }

    if(temp==0)
    {
        //NOT FOUND 
        printf("\nKey not found ! ") ; 
    }

    else
    {
        if(parent ==0) return 0 ;
        parent->next = temp->next ;
        free(temp) ; 
    }
    return first ; 
}


node * insert_after_key(node * first ,  int data,  int key)
{
    node * temp = first  , *parent = 0 ;  
    node * newnode = (node * ) malloc(sizeof(node)) ; 
    newnode->data = data ; 
    
    while(temp && temp->data!=key)
    {
        parent = temp ; 
        temp = temp->next ; 
    }

    if(parent ==0 )
        {
            //EMPTY LIST
            newnode->next =  0 ;
            return newnode ; 
        }
    
    if(temp==0)
    {
        printf("\nKey element not found ! ") ; 
    }
    else
    {
        newnode->next = parent->next ; 
        parent->next = newnode ;
    } 
    
    return first ; 
}


void display(node * first)
{
    if(!first) return ; 
    printf("\n") ; 
    for( ; first ; first = first->next)
        printf("%d " , first->data) ; 

}


int main()
{
   int i = 0 ; 
   node  * first = insert_last(0) ; 

   for(i = 1 ; i<10 ; i++) 
   {
    first = insert_last(first ,i )  ; 
   }

   display(first)  ; 

   first = delete_first(first) ; 
   display(first) ; 

   first = delete_last(first) ; 
   display(first) ; 

   first = delete_key(first  , 5) ; 
   display(first) ; 

   first = insert_after_key(first , 100 , 6) ; 
   display(first) ; 

   first = insert_last(first , 10) ; 
   display(first) ; 



}