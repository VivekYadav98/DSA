//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    long long int fibSum(long long int N){
        long long int n = N;
        if(n<=1)return n;
        
        long long int prev2 = 0;
        long long int prev1 = 1;
        long long int curr = 0;
        long long int ans = 1;
        int mod = 1000000007;
        
        for(int i=2;i<=n;i++)
        {
            curr = (prev1+prev2)%mod;
            prev2 = prev1;
            prev1 = curr;
            
            ans = (ans+curr)%mod;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends