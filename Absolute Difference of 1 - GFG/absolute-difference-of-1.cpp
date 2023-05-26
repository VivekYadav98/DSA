//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    vector<long long> getDigitDiff1AndLessK(long long *arr, int n, long long k) {
        vector<long long>ans;
        for(int i=0;i<n;i++)
        {
            int num = arr[i];
            bool flag = true;
            
            if(num<k && num>9)
            {
                string s = to_string(num);
                for(int j=0;j<s.length()-1;j++)
                {
                    if(abs((s[j]-'0') - (s[j+1]-'0')) != 1)
                    {
                        flag = false;
                        break;
                    }
                }
                
                if(flag == true)
                {
                    ans.push_back(num);
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
        long long k;
        cin >> n >> k;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        auto ans = obj.getDigitDiff1AndLessK(arr, n, k);
        for (auto x: ans) {
            cout << x << " ";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";

    }
    return 0;
}

// } Driver Code Ends