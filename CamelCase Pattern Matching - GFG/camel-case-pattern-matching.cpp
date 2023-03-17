//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string>ans;
        for(int i=0;i<N;i++)
        {
            string s = Dictionary[i];
            int x=0,y=0;
            
            while(x<s.length() && y<Pattern.length())
            {
                int num = int(s[x]);
                if(num>=65 && num<=90 && s[x] != Pattern[y])
                {
                    break;
                }
                
                if(s[x] == Pattern[y])
                {
                    x++;
                    y++;
                }
                else
                {
                    x++;
                }
            }
            
            if(y == Pattern.length())
            {
                ans.push_back(s);
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
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends