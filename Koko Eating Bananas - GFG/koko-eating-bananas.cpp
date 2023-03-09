//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& piles, int H) {
        long long int s=1,e=1e14;
        long long int mid = s + (e-s)/2;
        long long int count = 0;

        while(s<=e)
        {
            for(int i=0;i<piles.size();i++)
            {
                if(piles[i] < mid)
                {
                    count++;
                }
                else if(piles[i] % mid == 0)
                {
                    count += piles[i]/mid;
                }
                else
                {
                    count += piles[i]/mid + 1;
                }
            }

            if(count <= H)
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
            count = 0;
            mid = s + (e-s)/2;
        }
        return mid;  
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