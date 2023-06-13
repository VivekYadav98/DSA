//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        int N = arr.size();
        vector<int>ans;
        for(int i=0;i<n-1;i++)
        {
            arr.push_back(arr[i]);
        }
        stack<int>s;
        
        n = arr.size();
        s.push(arr[n-1]);
        ans.push_back(-1);
        
        int i=n-2;
        while(i>=0)
        {
            while(!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            
            s.push(arr[i]);
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        while(ans.size()>N)
        {
            ans.pop_back();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends