#include<bits/stdc++.h> 

using namespace std ; 
#define mul(a,b) ((a-'0')*(b-'0'))
#define i(a) (a-'0')
 

void makeequallength(string& , string&) ; 


string addstrings(string a, string b)
{
    int carry = 0  , temp_sum  , i , j ; 
    string sum = "" ; 

    for( i = a.length()-1 , j = b.length()-1 ; i>=0 && j>=0 ; j-- , i--)
    {
        temp_sum  = (a[i]-'0') + (b[j]-'0') + carry ; 
        carry = temp_sum /10 ; 
        temp_sum%=10 ; 
        sum = to_string(temp_sum) + sum ; 
    }
 

    while(j>=0)
    {
        temp_sum = b[j]-'0' + carry ; 
        carry = temp_sum/10 ; 
        temp_sum%=10 ; 
        sum = to_string(temp_sum)+sum ; 
        j--  ; 
    }

    while(i>=0)
    {
        temp_sum = a[i]-'0' + carry ;
        carry = temp_sum/10 ; 
        temp_sum%=10 ; 
        sum = to_string(temp_sum)+sum ; 
        i--  ; 
    }

       
    if(carry)
    {
        sum = to_string(carry) + sum ; 
        carry = 0 ;
    }

    cout<<"\nSum is " <<sum <<endl; 
    return sum ; 
}



string multiply(string A , string B)
{
    if(A.length()==1)
    {
        return to_string(mul(A[0] , B[0])) ; 
    }

    if(A.length()==2 )//means both A and B are of length 2
    {
        int a0 = i(A[1]) , a1 =i(A[0]) , b0 = i(B[1]) , b1 = i(B[0]) ; 
        int c2 = a1*b1  , c0 = a0*b0  , c1 = (a0+a1) * (b0+b1) - c0 - c2 ; 

        return to_string(c2*100 + c1*10 + c0) ; 
    }

    if(A.length()%2) //handle the odd number of digits case
    {
        A = "0" + A ;
        B = "0" + B ; 
    }

    string a0 , a1 , b0 , b1  , ten_2 , ten_1  , c2 , c1  ,c0 ; 

    a1 = A.substr(0 , A.length()/2) ; 
    a0 = A.substr(A.length()/2  ) ; 
    b1 = B.substr(0 , B.length()/2) ; 
    b0 = B.substr(B.length()/2  ) ; 


    for(int i = A.length() ; i>0 ; i--)
    {
        ten_2+="0" ; 
    }

    for(int i = A.length()/2 ; i>0 ; i--) ten_1+="0" ; 

    c2 = multiply(a1 , b1) ; 
    c0 = multiply(a0  ,b0) ; 
    c1 = addstrings(multiply(a0 , b1) , multiply(a1 , b0)) ; 
    cout<<c1 ; 

    return addstrings(addstrings(c2 +ten_2 , c1+ten_1) , c0) ; 
}



void makeequallength(string& A , string& B)
{
    while(A.length()<B.length())
    {
        A = "0" + A ; 
    }
    while(B.length()<A.length())
    {
        B = "0" + B ; 
    }

    if(A.length()%2)
    {
        A = "0" + A ; 
        B = "0"  + B ; 
    }
}


int main(void)
{
    string A = "20896" ; 
    string B = "12738" ; 
    cin>>A >> B ; 
    makeequallength(A , B) ; 
    cout<< multiply(A , B) ; 
    // cout<< addstrings(A , B) ; 
}


