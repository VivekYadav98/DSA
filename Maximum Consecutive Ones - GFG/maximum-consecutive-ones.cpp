//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        int i=0,j=0,ans=0;
        while(j<n)
        {
            if(nums[j] == 1)
            {
                ans = max(ans,j-i+1);
                j++;
            }
            else if(nums[j] == 0 && k>0)
            {
                k--;
                ans = max(ans,j-i+1);
                j++;
            }
            else
            {
                while(k==0)
                {
                    if(nums[i] == 1)
                    {
                        i++;
                    }
                    else
                    {
                        k++;
                        i++;
                    }
                }
            }
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
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends