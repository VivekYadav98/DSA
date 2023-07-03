//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends



bool metaStrings (string S1, string S2)
{
    if(S1 == S2)
    {
        return false;
    }
    
    if(S1.length() != S2.length())
    {
        return false;
    }
    
    unordered_map<char,char>m;
    int cnt = 0;
    for(int i=0;i<S1.length();i++)
    {
        if(S1[i] != S2[i] && cnt == 0)
        {
            m[S1[i]] = S2[i];
            cnt++;
        }
        else if(S1[i] != S2[i] && cnt == 1)
        {
            if(m[S2[i]] != S1[i])
            {
                return false;
            }
            cnt++;
        }
        else if(S1[i] != S2[i] && cnt == 2)
        {
            return false;
        }
    }
    
    if(cnt == 1 || cnt>2)
    {
        return false;
    }
    
    return true;
}