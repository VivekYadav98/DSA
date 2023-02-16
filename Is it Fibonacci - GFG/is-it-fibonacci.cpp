//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        vector<long long>ans;
        int i=0,j=0;
        long long sum = 0;
        
        for(int ind=0;ind<K;ind++)
        {
            ans.push_back(GeekNum[ind]);
        }
        
        while(j<N)
        {
            if(j-i+1 <= K)
            {
                sum += ans[j];
                j++;
            }
            else if(j-i+1 > K)
            {
                ans.push_back(sum);
                
                while(j-i+1 > K)
                {
                    sum -= ans[i];
                    i++;
                }
            }
        }
        return ans[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends