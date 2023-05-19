//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long solve(int i,vector<int>& A,int n,int indication,vector<vector<int>>& dp)
    {
        if(i>=n)
        {
            return 0;
        }
        
        if(dp[i][indication] != -1)
        {
            return dp[i][indication];
        }
        
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        if(indication == 1)
        {
            a = A[i] + solve(i+1,A,n,1,dp);
            b = solve(i+1,A,n,0,dp);
        }
        else
        {
            c = A[i] + solve(i+1,A,n,1,dp);
        }
        
        return dp[i][indication] = max({a,b,c});
    }
    
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<vector<int>>dp(N+1,vector<int>(2,-1));
        return solve(0,A,N,1,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends