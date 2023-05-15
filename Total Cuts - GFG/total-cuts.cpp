//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        int large[N-1];
        int small[N-1];
        
        large[0] = A[0];
        int maxi = A[0];
        
        for(int i=1;i<N-1;i++)
        {
            maxi = max(maxi,A[i]);
            large[i] = maxi;
        }
        
        small[N-2] = A[N-1];
        int mini = A[N-1];
        
        for(int i=N-2;i>0;i--)
        {
            mini = min(mini,A[i]);
            small[i-1] = mini;
        }
        
        int ans = 0;
        for(int i=0;i<N-1;i++)
        {
            if(small[i]+large[i] >= K)
            {
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends