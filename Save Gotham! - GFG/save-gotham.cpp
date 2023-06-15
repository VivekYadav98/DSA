//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {
    
    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << save_gotham(arr, n) << endl;
    }
    
	return 0;
}
// } Driver Code Ends


int save_gotham(int arr[], int n)
{
        vector<int>ans;
        int sum = 0;
        ans.push_back(0);
        stack<int>st;
        st.push(arr[n-1]);
        int i=n-2;
        
        while(i>=0)
        {
            while(!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                ans.push_back(0);
            }
            else
            {
                sum += st.top();
                ans.push_back(st.top());
            }
            
            st.push(arr[i]);
            i--;
        }
        
        return sum;
}