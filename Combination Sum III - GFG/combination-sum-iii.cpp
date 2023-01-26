//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(int arr[],int target,int K,vector<int>& temp,vector<vector<int>>& ans,int i)
    {
       if(i>=9 || temp.size() >= K)
       {
           if(target == 0 && temp.size() == K)
           {
               ans.push_back(temp);
           }
           return;
       }

       solve(arr,target,K,temp,ans,i+1);

       if(arr[i] <= target)
       {
           temp.push_back(arr[i]);
           solve(arr,target-arr[i],K,temp,ans,i+1);
           temp.pop_back();
       }
    }

    vector<vector<int>> combinationSum(int K, int N) {
        int arr[9] = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>temp;
        solve(arr,N,K,temp,ans,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends