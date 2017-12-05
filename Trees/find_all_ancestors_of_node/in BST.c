#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data ; 
    struct node * left , * right ;
}node ;



node * insert_node(node * root  , int data) 
{
    
    node * newnode= (node * )malloc(sizeof(node)) ; 
    newnode->data = data ; 
    newnode->left = newnode->right  = 0 ;

    if(root==NULL) { root = newnode ;  return root ; }

    node * temp = root  , *parent =  0 ;

    
    while(temp)
    {
        parent = temp ;
        if(data<temp->data)
        {
            temp = temp->left ;
        }
        else temp = temp->right;
    }

    if(data<parent->data)
        (parent->left = newnode) ; 
    else (parent->right= newnode) ;
    return root ; 
    
}



void display(node *  root )
{
    if(root==0) return ; 
    display(root->left) ;
    printf("%d " , root->data) ; 
    display(root->right) ; 
}


void find_ancestors(node * root  , int key)
{

    if(root==0 ||  root->data==key) return ;

    if(key<root->data) find_ancestors(root->left , key) ; 
    else find_ancestors(root->right , key) ; 

    printf("%d " , root->data) ;
}




int main()
{
    node * root = 0 ;
    int a[] = {15 , 10 , 100 , 125 ,5 , 11 , 75 , 4 , 3 , 6 } ;
    
    root = insert_node(root , 0) ;

    for(int i = 0; i<(sizeof(a)/sizeof(a[0])) ; i++)
        insert_node(root , a[i]) ;

    
    display(root) ;  printf("\n") ;

    find_ancestors(root , 6 ) ;
   
    
}