//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    vector<int> longestCommonPrefix(string str1, string str2){
        vector<int>ans(2,0);
        int maxi = 0;
        for(int i=0;i<str2.length();i++)
        {
            int count = 0;
            int k=i;
            for(int j=0;j<str1.length();j++)
            {
                if(k<str2.length() && str2[k] == str1[j])
                {
                    count++;
                    
                    if(count>maxi)
                    {
                        ans[1] = j;
                        maxi = count;
                    }
                    k++;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        string str1,str2;
        cin >> str1>> str2;
        Solution ob;
        vector<int> p;
        p = ob.longestCommonPrefix(str1,str2);
        if(p[0]==-1)
        cout<<"-1\n";
        
        else
        cout<<p[0]<<" "<<p[1]<<"\n";
    }
    return 0;
}

// } Driver Code Ends