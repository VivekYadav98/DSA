//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& piles, int H) {
        int s=1,e=INT_MAX,ans,mid;
        
        while(s<=e)
        {
            mid = e+(s-e)/2;
            
            int temp = 0;
            for(int i=0;i<piles.size();i++)
            {
                temp += piles[i]/mid;
                
                if(piles[i]%mid != 0)
                {
                    temp++;
                }
            }
            
            if(temp <= H)
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                s = mid+1;
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
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends