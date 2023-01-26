//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void solve(int ind,vector<int>& temp,vector<int>& arr,vector<vector<int>>& ans,int target)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind && arr[i] == arr[i-1])
            {
                continue;
            }

            if(arr[i] > target)
            {
                break;
            }

            temp.push_back(arr[i]);
            solve(i+1,temp,arr,ans,target-arr[i]);
            temp.pop_back();
        }
    }

    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,temp,arr,ans,k);
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends