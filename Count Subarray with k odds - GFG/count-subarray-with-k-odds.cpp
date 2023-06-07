//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2 != 0)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        }
        
        vector<int>preSum(n,0);
        unordered_map<int,int>m;
        preSum[0] = nums[0];
        m[preSum[0]]++;
        
        if(preSum[0] == k)
        {
            ans++;
        }
        
        for(int i=1;i<n;i++)
        {
            preSum[i] = preSum[i-1]+nums[i];
            
            if(preSum[i] == k)
            {
                ans++;
            }
            if(m.find(preSum[i]-k) != m.end())
            {
                ans += m[preSum[i]-k];
            }
            
            m[preSum[i]]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends