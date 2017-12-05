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
    return first ; 
}

node * delete_first(node * first)
{
    if(!first) return first ; 
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


node * insert_before_key(node * first ,  int data,  int key)
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
    for( ; first ; first = first->next)
        printf("%d " , first->data) ; 

    printf("\n") ; 
}


node * delete_all_keys(node * first , int key)
{
    node * temp = first  , *parent = first  , *todelete = 0 ; 
    if(!first) return ; 

    while(temp)
    {
        if(temp->data==key)
        {
            if(temp ==first) { todelete = first ; first = first->next ; free(todelete) ;  } 
            else
            {
                todelete = temp ; 
                parent->next = temp->next ; 
                free(todelete) ; 
            }
       }

       parent = temp ; 
       temp = temp->next ;
    }
    return first ; 
}


int main()
{
   int i = 0 ; 
   node  * first  = 0 ; 
   first = insert_last(first  , 0 ) ;

   for(i = 1 ; i<10 ; i++) 
   {
    first = insert_last(first ,i )  ; 
   }

   for(i = 6 ; i<14 ; i++) first = insert_last(first , i) ; 

   printf("All elements : ") ; 
   display(first)  ; 


   first = delete_first(first) ;
   printf("Delete first : ") ; 
   display(first) ; 

   first = delete_last(first) ; 
   printf("Delete last : ") ; 
   display(first) ; 

   first = delete_key(first  , 5) ; 
   printf("Delete key 5 : ") ; 
   display(first) ; 

   first = insert_before_key(first , 100 , 6) ; 
   printf("Insert 100 before key 6 : ") ; 
   display(first) ; 

   first = insert_last(first , 10) ; 
   printf("Insert 10 to the last : ") ; 
   display(first) ; 


   first = delete_all_keys(first , 6 )  ;
   printf("Delete All nodes with key 6 : ") ; 
   display(first) ; 

}