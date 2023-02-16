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
    
    int solve(vector<string>& words,int n,int i,int prev)
    {
        if(i == n)
        {
            return 0;
        }
        
        int len = solve(words,n,i+1,prev);
        if(prev == -1 || checkPossible(words[i],words[prev]))
        {
            len = max(len, 1 + solve(words,n,i+1,i));
        }
        return len;
    }
    int longestChain(int n, vector<string>& words) {
        vecto
        sort(words.begin(),words.end(),cmp);
       return solve(words,n,0,-1);
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