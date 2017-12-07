#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node
{
    int data; 
    struct node * left ; 
    struct node * right ; 
}node ; 



node * insert_first(node * first , int data) 
{

    node * newnode  = (node  *)malloc(sizeof(node)) ; 
    newnode->data = data ; 
    
    newnode->left = 0 ; 
    newnode->right = first ; 

    if(first)first->left = newnode ; 
    newnode->data = data ; 
    return newnode ; 

}



node * insert_last(node * first , int data )
{
    node * newnode  = (node  *)malloc(sizeof(node)) ; 
    newnode->data = data ; 
    newnode->right = 0 ; 
    newnode->left = 0 ; 

    if(!first) return newnode ; 
    node * temp = first ; 
    while(temp->right)
    {
        temp = temp->right ; 
    }
    newnode->left = temp ;
    temp->right = newnode ;

    return first ; 
    
}



node * insert_after_key(node * first ,int data ,  int key)
{
    
    node * newnode  = (node  *)malloc(sizeof(node)) ; 
    newnode->data = data ; 
    newnode->left = newnode->right = 0 ;
    node * temp = first   ;

    while(temp && temp->data!=key)
    {
        temp = temp->right ; 
    }

    if(!temp){
        printf("key not found ! ") ; 
        return first ; 
    }

    newnode->right = temp->right ; 
    newnode->left = temp ;
    if(temp->right) temp->right->left = newnode ; 
    temp->right = newnode ; 
    
    return first ; 
}


node * delete_first(node * first)
{
    ;
    node * temp = first ; 
    if(!first) return first ; 
    first = first->right ; 
    first->left = 0 ;
    free(temp) ; 
    return first ; 
}


node * delete_last(node * first)
{
    if(!first) return first; 
    node * temp = first ; 
    
    while(temp->right)
    {
        temp = temp->right ; 
    }

    if(temp==first) {free(first) ; return 0 ; }

    temp->left->right = 0 ; 
    
    return first ; 
}

node * delete_key(node * first , int key)
{
    if(!first) return first ; 
    node * temp = first ; 
    if(key==first->data)
    {
        if(first->right) first->right->left = 0 ;
        first = first->right;
        free(temp) ; 
        return first ; 
    }

    for(temp = first ; temp && temp->data!=key ; temp= temp->right) ; 
    
    if(!temp)
    {
        printf("key not found ! ") ; 
        return first ; 
    }

    temp->left->right = temp->right ; 
    if(temp->right)temp->right->left = temp->left ; 
    return first ; 
    
}



void display(node * first)
{
    if(!first) return ; 
    printf("\nFirst to Last :- ") ; 
    for( ; first->right ; first = first->right)
        printf("%d " , first->data) ; 

    printf("%d\nLast to First :- " , first->data) ;  

    for( ; first ; first = first->left)
    {
        printf("%d " , first->data) ; 
    }

    printf("\n\n") ; 
}




int main()
{
    int i = 0 ; 
   node  * first  = 0 ; 
   first = insert_last(first  , 0 ) ;
   srand(time(0));


   for(i = 1 ; i<10 ; i++) 
   {

    first = insert_last(first ,rand()%15 )  ; 
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

   first = insert_after_key(first , 100 , 6) ; 
   printf("Insert 100 after key 6 : ") ; 
   display(first) ; 

    first = insert_first(first , 10) ; 
    printf("Insert 10 to the first : ") ; 
    display(first) ; 

   first = insert_last(first , 10) ; 
   printf("Insert 10 to the last : ") ; 
   display(first) ; 
}