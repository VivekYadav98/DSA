//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int ind,vector<int>&A,int target,vector<int>&output,vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(output);
            return;
        }
        
        
        for(int i=ind;i<A.size();i++)
        {
           if(i>ind && A[i] == A[i-1])
           {
               continue;
           }
           
           if(target < A[i])
           {
               break;
           }
            
          output.push_back(A[i]);
          solve(i+1,A,target-A[i],output,ans);
          output.pop_back();
        }
    }
     
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>output;
        solve(0,candidates,target,output,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends