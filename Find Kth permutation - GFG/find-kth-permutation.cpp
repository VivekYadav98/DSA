//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void nextPermutation(string& s)
    {
        int n = s.length();
        int x = -1,j=0;
        for(int i=n-1;i>0;i--)
        {
            if(s[i]-'0' > s[i-1]-'0')
            {
                x = i-1;
                break;
            }
        }
        
        // if(x == -1)
        // {
        //     reverse(s.begin(),s.end());
        // }
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]-'0' > s[x]-'0')
            {
                j=i+1;
                swap(s[i],s[x]);
                break;
            }
        }
        
        reverse(s.begin()+x+1,s.end());
    }
    
    string kthPermutation(int n, int k)
    {
        string s = "";
        for(int i=1;i<=n;i++)
        {
            s += i+'0';
        }
        
        for(int i=0;i<k-1;i++)
        {
            nextPermutation(s);
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends