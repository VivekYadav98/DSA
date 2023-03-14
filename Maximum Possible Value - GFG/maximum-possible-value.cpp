//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        int totalSticks = 0;
        long long ans = 0;
        int mini = INT_MAX;
        
        for(int i=0;i<N;i++)
        {
            if(B[i]%2 == 0)
            {
                totalSticks += B[i];
                ans += B[i]*A[i];
                mini = min(mini,A[i]);
            }
            else
            {
                B[i] = B[i]-1;
                if(B[i]>0)
                {
                    mini = min(mini,A[i]);
                }
                totalSticks += B[i];
                ans += B[i]*A[i];
            }
        }
        
        if(totalSticks%4 != 0)
        {
            totalSticks = totalSticks%4;
            ans -= totalSticks*mini;
            return ans;
        }
        else
        {
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends