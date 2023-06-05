//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    ll mod = 1e9+7;
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<vector<ll>>arr;
        arr.push_back({1});
        int k=1;
        
        while(k<=n)
        {
            vector<ll>temp;
            temp.push_back(1);
            
            vector<ll>a = arr.back();
            
            for(int i=0;i<a.size()-1;i++)
            {
                temp.push_back((a[i]+a[i+1])%mod);
            }
            
            temp.push_back(1);
            arr.push_back(temp);
            k++;
        }
        
        return arr[n-1];
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