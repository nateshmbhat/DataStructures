#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct node{
    char name[100] ; 
    struct node * next; 
}node ; 

node * insert_last(node * last ,  char * name)
{
    node * newnode = (node * )malloc(sizeof(node)) ; 
    strcpy(newnode->name , name) ; 
    newnode->next = newnode ;

    if(!last) return newnode ; 

    newnode->next = last->next ; 
    last->next = newnode ; 
    return newnode ; 
}


node * delete_node(node * list)
{
    if(!list) return 0 ; 
    node * todelete = list->next ; 

    printf("%s " , todelete->name) ; 
    list->next = todelete->next ; 
    free(todelete) ;
    return list ; 
}

int main(void)
{
    int n , soldiers   ; char name[100] ; 
    node * list = 0 ; 
    printf("Enter number of soldiers : ") ; scanf("%d" , &soldiers) ; 
    printf("Enter n : ") ; scanf("%d" , &n) ; 

    int i = 0; 
    for(i =0 ; i< soldiers ; i++)
    {
        printf("Enter name : ") ;
        scanf("%s" , name) ; 
        list = insert_last(list , name) ;  
    }

    while(list->next!=list)
    {
        for(i = 1; i< n ; i++)
            list = list->next ;

        list = delete_node(list) ;        
    }
    printf("\n\nSoldier who escapes is : %s" , list->name) ; 
        
}