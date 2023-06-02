//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    if(N == 1)
	    {
	        return A[0];
	    }
	    else if(A[0] != A[1])
	    {
	        return A[0];
	    }
	    else if(A[N-1] != A[N-2])
	    {
	        return A[N-1];
	    }
	    
	    
	   int s=0,e=N-1;
	   while(s<=e)
	   {
	       int mid = (s+e)/2;
	       
	       if(A[mid] != A[mid-1] && A[mid] != A[mid+1])
	       {
	           return A[mid];
	       }
	       else if(A[mid] == A[mid+1])
	       {
	           mid++;
	           if((mid-s+1)%2 == 0)
	           {
	               s = mid+1;
	           }
	           else
	           {
	               e = mid-1;
	           }
	       }
	       else
	       {
	           if((mid-s+1)%2 == 0)
	           {
	               s = mid+1;
	           }
	           else
	           {
	               e = mid-1;
	           }
	       }
	   }
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends