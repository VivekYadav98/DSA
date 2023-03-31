//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalizeArray(int N, int k, int A[]){
        long long int mod = 1e9+7;
        sort(A,A+N);
        int ans=0;
        int target = A[N/2];
        
        for(int i=0;i<N;i++)
        {
            int num = abs(A[i]-target);
            if(num%k != 0)
            {
                return -1;
            }
           ans += num/k;
           ans = ans%mod;
        }
        
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, k;
        cin>>N>>k;
        int A[N];
        for(int i = 0; i < N; i++)
            cin>>A[i];
            
        Solution ob;
        cout<<ob.equalizeArray(N, k, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends