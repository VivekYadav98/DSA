//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
  void solve(vector<int>& nums, int index,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(index>=nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
//         exclude
        solve(nums, index+1,temp,ans);
        
//         include
        temp.push_back(nums[index]);
        solve(nums, index+1,temp,ans);  
        temp.pop_back();
    }
    
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve( nums,0,temp,ans);
        set<vector<int>>s;
        for(auto i:ans)
        {
            s.insert(i);
        }

       ans.clear();
        for(auto i:s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends