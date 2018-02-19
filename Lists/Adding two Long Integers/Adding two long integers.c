#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct node{
    int data ; 
    struct node * next ; 
} node ; 


void  convert_string_to_list(node * head  , char * string)
{
    int i = 0  ;

    for(i =0 ; i<strlen(string) ; i++)
    {
        node * newnode = (node * )malloc(sizeof(node)) ; 
        newnode->data = string[i]-'0' ;
        
        newnode->next  = head->next ; 
        head->next = newnode ; 
        head->data ++ ;
    }

}

void add_two_numbers(node * head1 , node * head2 , node * head3)
{
   long sum =0 ; int i = 0 , carry = 0 ; 
   node * list1 = head1->next , *list2 = head2->next ; 
   while(list1 || list2)
   {
       sum = carry + (list1?list1->data : 0  + (list2?list2->data:0)) ;
       carry = sum/10 ;

       node * newnode = (node *)malloc(sizeof(node)) ;
       newnode->data = sum%10 ; 
       newnode->next = head3->next ; 
       head3->next = newnode ;
   }

   if(carry)
   {
        node * newnode = (node *)malloc(sizeof(node)) ;
        newnode->data = carry ;
        newnode->next = head3->next ; 
        head3->next = newnode ;    
   }

}


void Display(node * head )
{
    puts("") ; 
    for(node * temp = head->next ; temp ; temp= temp->next)
    {
        printf("%d" , temp->data ) ; 
    }
}


int main(void)
{
    char num1[10] = "123" , num2[] = "456" ;
    node head1 = {0}, head2={0} , head3={0} ;

    convert_string_to_list(&head1 , num1) ; 
    Display(&head1) ; 
    convert_string_to_list(&head2 , num2)  ;
    Display(&head2) ; 

    add_two_numbers(&head1  , &head2 , &head3) ; 
    Display(&head3) ;



}