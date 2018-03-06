//FIND ALL THE TRIPLETS WHICH SUM UP TO ZERO 
#include<bits/stdc++.h>

using namespace std ;

int main(void)
{
	int arr[] = {0 , -1 ,  2 , -3 , 1} ; 
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));
	int n = vec.size() ; 

	//Naive way
	// for(int i =0 ; i<n-2 ; i++)
	// {
	// 	for(int j = i+1 ; j<n-1 ; j++)
	// 	{
	// 		for(int k = j+1 ; k<n ; k++)
	// 		{
	// 			if((arr[i] + arr[j] + arr[k])==0)
	// 				cout<<arr[i] <<arr[j] <<arr[k] <<endl; 
					
	// 		}
	// 	}
	// }


	//Takes O(n2) and O(n) space
	// unordered_set<int> s;
	// for(int i =0 ; i < n-1 ; i++)
	// {
	// 	s.clear() ; 
	// 	for(int j =i+1 ; j<n ; j++)
	// 	{
	// 		if(s.find(-(arr[i]+arr[j]))!=s.end())
	// 			cout<<arr[i] << arr[j] << -(arr[i]+arr[j]) <<endl; 	
	// 		else{
	// 			s.insert(arr[j]) ; 
	// 		}
	// 	}
	// }


	//Optimal solution
	sort(vec.begin()  , vec.end()) ; 

	for(int i=0 ; i < n-1 ; i++)
	{
		int p1 = i+1  , p2 = n-1 ;  
		while(p1<p2)
		{
			if(arr[p1]+arr[p2]==-arr[i])
			{
				cout<<arr[p1] <<arr[p2] <<arr[i] <<endl; 
				p2-- , p1++ ; 
			}
			else if(arr[p1]+arr[p2]>-arr[i])
				p2-- ; 
			else p1++;
		}
	}
}