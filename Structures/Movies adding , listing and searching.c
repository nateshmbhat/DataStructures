#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct movies
{
    char name[20]  , producer[20] ;
    struct movie_info
    {
        float rating ;
        int duration ;
    }m ;
}M[20]  ;



void search_movie(struct movies M[]  , char * name , int n  )
{
   for(int i =0 ; i< n ; i++)
   {
       if(strcmp(M[i].name , name)==0)
       {
           printf("\nMovie Details are : ") ; 
           printf("Name : %s\nProducer : %s\nDuration : %d\nRating : %f\n" , M[i].name , M[i].producer , M[i].m.duration , M[i].m.rating) ; 
       }
   } 
}


void sort_movies_based_on_rating(struct movies M[] , int n)
{
    struct movies temp ; 
for(int i = 0 ; i<n-1 ; i++)
    {
        for(int j = 0 ; j<n-i ; j++)
        {
           if(M[j].m.rating<M[j+1].m.rating) 
           {
              temp = M[j] ; 
              M[j] = M[j+1] ;
              M[j+1] = temp ;  
           }
        }
        
    }
}


void display(struct movies M[] , int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        printf("Name : %s\nProducer : %s\nDuration : %d\nRating : %f\n" , M[i].name , M[i].producer , M[i].m.duration , M[i].m.rating) ; 
    }
}



int main()
{
    int a[10] ; 
    int n = 20 ; 
    struct movies M[20] ;   
    for(int i = 0 ; i<n ; i++)
    { 
        strcpy(M[i].name  , "Name" ) ; 
        strcpy(M[i].producer ,  "Producer" ) ; 
        M[i].m.duration = 20-i ;
        M[i].m.rating = i +1.43 ;
    }

    // display(M , n ) ;
    // search_movie(M ,  "Name" , n ) ;
    sort_movies_based_on_rating(M , n)  ; 
    display(M , n ) ; 

}