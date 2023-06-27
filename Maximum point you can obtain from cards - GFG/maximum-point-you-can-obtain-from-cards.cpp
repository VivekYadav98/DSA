//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        int i=0,j=0,n=cardPoints.size(),window=n-k,ans=0,sum=0,total=0;
        for(auto i:cardPoints)
        {
            total += i;
        }

        if(k >= n)
        {
            return total;
        }

        while(j<n)
        {
            sum += cardPoints[j];
            if(j-i+1 < window)
            {
                j++;
            }
            else
            {
                ans = max(ans,total-sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends