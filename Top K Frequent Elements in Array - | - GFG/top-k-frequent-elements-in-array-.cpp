//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  static bool cmp(pair<int,int>a,pair<int,int>b)
    {
        if(a.second == b.second)
        {
            return a.first>b.first;
        }
        else
        {
            return (a.second>b.second);
        }
    }
    
    vector<int> topK(vector<int>& nums, int k) {
         map<int,int>m;
        for(auto i:nums)
        {
            m[i]++;
        }
        
        vector<pair<int,int>>ans;
        for(auto i:m)
        {
           ans.push_back({i.first,i.second});
        }
        
        sort(ans.begin(),ans.end(),cmp);
        
        vector<int>res;
        for(int i=0;i<k;i++)
        {
            res.push_back(ans[i].first);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends