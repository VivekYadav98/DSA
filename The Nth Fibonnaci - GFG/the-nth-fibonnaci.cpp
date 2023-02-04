//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int fib(int N){
        int n = N;
        if(n<=1)return n;
        
        long long int prev2 = 0;
        long long int prev1 = 1;
        long long int curr = 0;
        
        for(int i=2;i<=n;i++)
        {
            curr = (prev1+prev2)%10;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1%10;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.fib(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends