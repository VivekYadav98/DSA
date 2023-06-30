//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int ind,int length,int target,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(temp.size() == length && target == 0)
        {
           ans.push_back(temp);
           return;
        }
        
        for(int i=ind;i<=9;i++)
        {
            if(target < i)
            {
                break;
            }
            
            temp.push_back(i);
            solve(i+1,length,target-i,temp,ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int K, int N) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,K,N,temp,ans);
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