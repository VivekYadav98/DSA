//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int ind,int target,vector<int>& arr,vector<vector<int>>& dp)
	{
	    if(target = 0)
	    {
	        return true;
	    }
	    
	    if(ind == 0)
	    {
	        return (target == arr[0]);
	    }
	    
	    if(dp[ind][target] != -1)
	    {
	        return dp[ind][target];
	    }
	    
	    bool left = solve(ind-1,target,arr,dp);
	    bool right = false;
	    
	    if(target >= arr[ind])
	    {
	      right = solve(ind-1,target-arr[ind],arr,dp);
	    }
	    
	    return dp[ind][target] = left | right;
	}
	
	
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        
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
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends