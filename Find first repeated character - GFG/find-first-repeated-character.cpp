//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    string ans = "";
    unordered_map<char,int>m;
    for(int i=0;i<s.length();i++)
    {
        if(m.find(s[i]) != m.end())
        {
            ans = s[i];
            return ans;
        }
        m[s[i]]++;
    }
    return "-1";
}