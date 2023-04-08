//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isProduct(int arr[], int n, long long x) {
       
        unordered_set<long long >st;
        for(int i=0;i<n;i++){
            
            if(arr[i]!=0 && abs(x)>=abs(arr[i])){
                
                if(abs(x)%abs(arr[i])==0){
                     
                     if(st.find(x/arr[i])!=st.end()){
                         return true;
                     }
                     else {
                         st.insert(arr[i]);
                     }
                }
                
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        long long x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.isProduct(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
// } Driver Code Ends