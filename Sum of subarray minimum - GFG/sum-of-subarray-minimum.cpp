//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int N, vector<int> &arr) {
        int mod = 1e9+7;
        vector<int>prev,next;
        stack<int>st;
        
        st.push(0);
        prev.push_back(1);
        int i=1;
        
        while(i<N)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                prev.push_back(i+1);
            }
            else
            {
                prev.push_back(i-st.top());
            }
            
            st.push(i);
            i++;
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        
        st.push(N-1);
        next.push_back(1);
        i=N-2;
        
        while(i>=0)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                next.push_back(N-i);
            }
            else
            {
                next.push_back(st.top()-i);
            }
            
            st.push(i);
            i--;
        }
        reverse(next.begin(),next.end());
        
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            int prod = (prev[i]*next[i])%mod;
            prod = (prod*arr[i])%mod;
            ans = (ans+prod)%mod;
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
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends