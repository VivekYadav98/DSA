//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  void solve(int arr[],int n,vector<vector<bool>>& dp,int sum)
  {
        for(int ind=0;ind<n;ind++)
        {
            dp[ind][0] = true;
        }
        dp[0][arr[0]] = true;
        
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notPick = dp[ind-1][target];
        	    bool pick = false;
        	    
        	    if(target >= arr[ind])
        	    {
        	      pick = dp[ind-1][target-arr[ind]];
        	    }
        	    
        	    dp[ind][target] = pick | notPick;
            }
        }
  }
	int minDifference(int arr[], int n)  { 
	    int totalSum = 0;
	    for(int i=0;i<n;i++)
	    {
	        totalSum += arr[i];
	    }
	    vector<vector<bool>>dp(n,vector<bool>(totalSum+1,false));
	    solve(arr,n,dp,totalSum);
	    
	    int ans = INT_MAX;
	    for(int i=0;i<=totalSum;i++)
	    {
	        if(dp[n-1][i] == true)
	        {
	            int s1 = i;
	            int s2 = totalSum-i;
	            ans = min(ans,abs(s1-s2));
	        }
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends