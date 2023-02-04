//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

   void solve(int i,int j,int n,int m,long long& ans)
    {
        if(i==n-1 && j==m-1)
        {
            ans++;
            return;
        }
        
        if(i>=n || j>=m)
        {
            return;
        }
        
        solve(i+1,j,n,m,ans);
        solve(i,j+1,n,m,ans);
    }

long long  numberOfPaths(int m, int n)
{
    long long ans = 0;
    solve(0,0,n,m,ans);
    return ans;
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends