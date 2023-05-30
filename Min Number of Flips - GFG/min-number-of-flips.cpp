//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    int ans1 = 0,ans2=0;
    int n = S.length();
    
    if(n%2 != 0)
    {
        if(S[n-1] != '1')
        {
            ans1++;
        }
        
        if(S[n-1] != '0')
        {
            ans2++;
        }
    }
    
    for(int i=0;i<n-1;i+=2)
    {
        if(S[i] == '1' && S[i+1] == '0')
        {
            continue;
        }
        
        if(S[i] != '1')
        {
           ans1++;
        }
        if(S[i+1] != '0')
        {
            ans1++;
        }
    }
    
    for(int i=0;i<n-1;i+=2)
    {
        if(S[i] == '0' && S[i+1] == '1')
        {
            continue;
        }
        
        if(S[i] != '0')
        {
           ans2++;
        }
        if(S[i+1] != '1')
        {
            ans2++;
        }
    }
    return min(ans1,ans2);
}