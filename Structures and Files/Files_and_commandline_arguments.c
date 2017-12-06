#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


char a[100] ;
char * str_rev(char str[])
{
    int j = 0; 
    for(int i =strlen(str)-1 ; i>=0 ; i--)
        a[j++] = str[i] ; 
    a[j++] = 0 ;
    return a ; 
}



int main(int argc , char * argv[])
{
    char s[100]  ;
    printf("argc = %d" , argc) ; 
    for(int i =1 ; i<argc ; i++)
    {
        strcpy(s , str_rev(argv[i])) ;
        printf("\n%s" , s) ;
    }
        // strcpy(s , str_rev(argv[i])) ;
        // printf("%s " , s) ;

}

