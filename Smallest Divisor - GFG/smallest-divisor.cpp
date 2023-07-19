//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestDivisor(vector<int>& nums, int K) {
        int s=0,e=INT_MAX,mid,ans;
        
        while(s<=e)
        {
            mid = e+(s-e)/2;
            
            int temp = 0;
            for(int i=0;i<nums.size();i++)
            {
                if(mid != 0)
                {
                    temp += nums[i]/mid;
                    
                    if(nums[i]%mid != 0)
                    {
                        temp++;
                    }
                }
            }
            
            if(temp <= K)
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        
        if(ans == 0)
        {
            return 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends