//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void solve(long long int num,int cnt,long long int n,vector<long long>& ans)
    {
        if(num>n)
        {
            return;
        }
        
        ans.push_back(num);
        solve(num*cnt,cnt+1,n,ans);
    }
    
    vector<long long> factorialNumbers(long long N)
    {
        vector<long long>ans;
        int cnt = 2;
        solve(1,cnt,N,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends