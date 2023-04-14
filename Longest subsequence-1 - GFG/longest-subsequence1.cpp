//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int prev,int n,int arr[])
    {
        if(i>=n)
        {
            return 0;
        }
        
        int pick = INT_MIN,notPick = INT_MIN;
        if(prev == -1 || abs(arr[i]-prev) == 1)
        {
            pick = 1+solve(i+1,arr[i],n,arr);
        }
        
        notPick = solve(i+1,prev,n,arr);
        return max(pick,notPick);
    }
    int longestSubsequence(int N, int A[])
    {
        
        return solve(0,-1,N,A);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends