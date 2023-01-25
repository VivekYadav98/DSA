//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        map<string,int>A;
        for(int i=0;i<n;++i){
            ++A[contact[i]];
        }
        vector<vector<string>>ans;
        for(int i=0;i<s.size();++i){
            vector<string>a;
            ans.push_back(a);
        }
        for(auto it:A){
            if(it.first[0]==s[0]){
                solve(it.first,s,ans);
            }
        }
        for(int i=0;i<ans.size();++i){
            if(ans[i].size()==0){
                string s3 = "";
                s3.push_back('0');
                ans[i].push_back(s3);
            }
        }
        return ans;
        
    }
    
    void solve(string s1,string s,vector<vector<string>>&ans){
        for(int i=0;i<s.size()&& i<s1.size();++i){
            if(s[i]==s1[i]){
                ans[i].push_back(s1);
            }
            else{
                return;
            }
        }
    }
    
    
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends