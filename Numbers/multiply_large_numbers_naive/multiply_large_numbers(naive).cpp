#include<bits/stdc++.h> 
using namespace std ; 
string addstrings(string , string ) ; 

// #define i(x) (x-'0')


string multiply(string &A , string& B) 
{
    int dA = A.length()  , dB = B.length()   , carry = 0 ; 
    vector<string> products; 

    for(int i =A.length()-1 ; i>=0; i--)
    {
        string product = "" ; 
        carry = 0 ; 
        int temp_product ;

        for(int j = B.length()-1 ; j>=0  ; j--)
        {
            temp_product = (B[j]-'0')* (A[i]-'0') + carry ;
            carry = temp_product/10 ;
            temp_product%=10 ; 
            product = to_string(temp_product) + product ; 
        }
        
        if(carry)
            product = to_string(carry) + product ; 

        for(int temp = 0 ; temp < A.length()-1 - i  ; temp++)
            product+="0" ; 

        products.push_back(product) ; 
        cout<<product ; 
        cout<<endl; 
    }


    //finding the sum of all the products 
    string sum ="" ; 
    for(int i =products.size()-1 ; i>=0 ; i--)
    {
       sum = addstrings(sum , products[i]) ; 
    }
    
    exit(0) ; 
   
}



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

    cout<<"\nSum is " <<sum <<endl; 
    return sum ; 
}



int main(void)
{
   string A  , B ;  
//    A   = "12" ; 
//    B = "23" ; 

   cin>>A >> B ;

   multiply(A , B ) ; 
   return 0 ; 
}