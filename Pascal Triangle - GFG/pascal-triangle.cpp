//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    int mod = 1e9+7;
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<vector<ll>>ans;
        if(n == 1)
        {
            return {1};
        }

        vector<ll>temp;
        ans.push_back({1});

        int cnt = 2;
        while(cnt <= n)
        {
            temp = ans.back();

            vector<ll>arr;
            arr.push_back(1);
            for(int i=1;i<temp.size();i++)
            {
                ll num = (temp[i] + temp[i-1])%mod;
                arr.push_back(num);
            }
            
            arr.push_back(1);
            ans.push_back(arr);
            cnt++;
        }

        return ans[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends