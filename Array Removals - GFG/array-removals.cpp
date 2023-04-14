//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
 
    int removals(vector<int>& arr, int k){
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int i=0,j=0;
        int ans = INT_MIN;
        
        while(j<n)
        {
           if(arr[j]-arr[i] <= k)
           {
               ans = max(ans,j-i+1);
               j++;
           }
           else
           {
               while(i<j && arr[j]-arr[i] > k)
               {
                   i++;
               }
               j++;
           }
        }
        
        return n-ans;
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends