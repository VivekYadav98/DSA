//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
 
	bool commonSubseq (string a, string b)
	{
	    int n = a.length();
	    int m = b.length();
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(a[i] == b[j])
	            {
	                return true;
	            }
	        }
	    }
	    
	    return false;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--) 
	{
		string a, b; cin >> a >> b;
		Solution ob;
		cout << ob.commonSubseq (a, b) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends