//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>prevSmaller(vector<int>& arr,int n)
    {
        vector<int>ans;
        ans.push_back(1);
        stack<int>st;
        st.push(0);
        int i=1;
        
        while(i<n)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                ans.push_back(i+1);
            }
            else
            {
                ans.push_back(i-st.top());
            }
            
            st.push(i);
            i++;
        }
        return ans;
    }
    
    vector<int>nextSmaller(vector<int>& arr,int n)
    {
        vector<int>ans;
        ans.push_back(1);
        stack<int>st;
        st.push(n-1);
        int i=n-2;
        
        while(i>=0)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                ans.push_back(n-i);
            }
            else
            {
                ans.push_back(st.top()-i);
            }
            
            st.push(i);
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    vector<int>prevGreater(vector<int>& arr,int n)
    {
        vector<int>ans;
        ans.push_back(1);
        stack<int>st;
        st.push(0);
        int i=1;
        
        while(i<n)
        {
            while(!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                ans.push_back(i+1);
            }
            else
            {
                ans.push_back(i-st.top());
            }
            
            st.push(i);
            i++;
        }
        return ans;
    }
    
    vector<int>nextGreater(vector<int>& arr,int n)
    {
        vector<int>ans;
        ans.push_back(1);
        stack<int>st;
        st.push(n-1);
        int i=n-2;
        
        while(i>=0)
        {
            while(!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                ans.push_back(n-i);
            }
            else
            {
                ans.push_back(st.top()-i);
            }
            
            st.push(i);
            i--;
        }
        
         reverse(ans.begin(),ans.end());
        return ans;
    }
    
    long long subarrayRanges(int n, vector<int> &arr) {
        vector<int>prevSmall = prevSmaller(arr,n);
        vector<int>nextSmall = nextSmaller(arr,n);
        vector<int>prevGreat = prevGreater(arr,n);
        vector<int>nextGreat = nextGreater(arr,n);
        
        long long ans1 = 0,ans2=0;
        for(int i=0;i<n;i++)
        {
            long long p1 = prevSmall[i]*nextSmall[i]*arr[i];
            long long p2 = prevGreat[i]*nextGreat[i]*arr[i];
            
            ans1 += p1;
            ans2 += p2;
        }
        
        // cout<<ans1<<" "<<ans2;
        return ans2-ans1;
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
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends