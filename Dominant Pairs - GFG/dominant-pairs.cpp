//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        int ind = n/2;
        sort(arr.begin(),arr.begin()+ind);
        sort(arr.begin()+ind,arr.end());
        int i=ind-1,j=n-1;
        int ans = 0;
        
        while(i>=0 && j>=n/2)
        {
            if(arr[i] >= 5*arr[j])
            {
                ans += j-ind+1;
                i--;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends