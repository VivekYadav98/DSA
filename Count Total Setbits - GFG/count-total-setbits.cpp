//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPower(int n)
    {
        int res = 0;
        while(1 << res <= n)
        {
            res++;
        }
        return res-1;
    }
    
    long long countBits(long long N) {
        if(N == 0)
        {
            return 0;
        }
        
        int x = maxPower(N);
        
        return (pow(2,x-1)*x + (N-pow(2,x)+1) + countBits(N-pow(2,x)));
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends