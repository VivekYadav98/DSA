//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long fact(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        
        return n*fact(n-1);
    }
    
    long long findRank(string str) {
        long long ans = 1;
        vector<int>cnt(256,0);
        
        int n = str.length();
        long long mul = fact(n);
        for(int i=0;i<str.length();i++)
        {
            cnt[str[i]]++;
        }
        
        for(int i=1;i<256;i++)
        {
            cnt[i] += cnt[i-1];
        }
        
        for(int i=0;i<n;i++)
        {
            mul = mul/(n-i);
            
            ans += cnt[str[i] -1]*mul;
            
            for(int j=str[i];j<256;j++)
            {
                cnt[j]--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends