//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == 'b' || s[i] == 'a' || s[i] == 'l' || s[i] == 'o' || s[i] == 'n')
            {
              m[s[i]]++;
            }
        }
        
        int ans = 0;
        while(true)
        {
            if(m.find('b') != m.end() && m.find('a') != m.end() && m.find('l') != m.end() &&
            m.find('o') != m.end() && m.find('n') != m.end() && m['l'] >= 2 && m['o'] >= 2)
            {
                ans++;
                m['b']--;
                if(m['b'] == 0)
                {
                    m.erase('b');
                }
                m['a']--;
                if(m['a'] == 0)
                {
                    m.erase('a');
                }
                m['l'] -= 2;
                if(m['l'] == 0)
                {
                    m.erase('l');
                }
                m['o'] -= 2;
                if(m['o'] == 0)
                {
                    m.erase('o');
                }
                m['n']--;
                if(m['n'] == 0)
                {
                    m.erase('n');
                }
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends