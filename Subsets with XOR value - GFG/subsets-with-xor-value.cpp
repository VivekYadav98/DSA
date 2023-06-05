//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    void solve(int i,vector<int>& arr,int n,int num,int& ans,int k)
    {
        if(i>=n)
        {
            if(num == k)
            {
                ans++;
            }
            return;
        }
        
        num = num^arr[i];
        solve(i+1,arr,n,num,ans,k);
        num = num^arr[i];
        solve(i+1,arr,n,num,ans,k);
    }
    
    
    int subsetXOR(vector<int> arr, int N, int K) {
        int ans = 0,num=0;
        solve(0,arr,N,num,ans,K);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends