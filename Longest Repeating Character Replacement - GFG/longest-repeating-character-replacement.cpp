//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        int i=0,j=0,ans=0;
        vector<int>freq(26,0);
        
        while(j<S.length())
        {
            freq[S[j]-'A']++;
            
            int cnt = 0;
            for(int i=0;i<26;i++)
            {
                cnt = max(cnt,freq[i]);
            }
            
            int window = j-i+1;
            if((window - cnt) <= K)
            {
                ans = max(ans,j-i+1);
                j++;
            }
            else
            {
                if((window - cnt) > K)
                {
                   freq[S[i]-'A']--;
                   i++;
                }
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
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends