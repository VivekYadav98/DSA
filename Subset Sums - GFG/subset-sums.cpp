//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int i,vector<int>& arr,int sum,int n,vector<int>& ans)
    {
        if(i>=n)
        {
            ans.push_back(sum);
            return;
        }
        
        solve(i+1,arr,sum,n,ans);
        solve(i+1,arr,sum+arr[i],n,ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        int sum = 0;
        solve(0,arr,sum,N,ans);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends