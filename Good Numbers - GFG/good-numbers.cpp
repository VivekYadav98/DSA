//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int>ans;
        for(int i=L;i<=R;i++)
        {
            if(i%10 != D)
            {
                int num = i;
                int sum = -1;
                bool flag  = true;
                
                while(num>0)
                {
                    int r = num%10;
                    
                    if(r == D)
                    {
                        flag = false;
                        break;
                    }
                    
                    if(r<=sum)
                    {
                        flag = false;
                        break;
                    }
                    
                    if(sum == -1)
                    {
                        sum = 0;
                    }
                    sum += r;
                    num = num/10;
                }
                
                if(flag == true)
                {
                    ans.push_back(i);
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
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends