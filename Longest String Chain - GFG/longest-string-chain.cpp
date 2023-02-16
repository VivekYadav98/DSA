//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool cmp(string& a,string& b)
    {
        return (a.size() < b.size());
    }
    
    bool checkPossible(string& s1,string& s2)
    {
        if(s1.size() != s2.size() + 1) return false;
        int first = 0;
        int second = 0;
        
        while(first < s1.size())
        {
            if(second<s2.size() && s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        
        if(first == s1.size() && second == s2.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int longestChain(int n, vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi = 1;
        int lastIndex = 0;
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
            
            for(int prev=0;prev<i;prev++)
            {
                if(checkPossible(words[i],words[prev]) && 1+dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends