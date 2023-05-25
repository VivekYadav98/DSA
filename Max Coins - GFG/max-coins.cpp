//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    int maxCoins(int n,vector<vector<int>> &ranges){
        vector<int>maxi(n,0);
        sort(ranges.begin(),ranges.end());
        
        maxi[n-1] = ranges[n-1][2];
        for(int i=n-2;i>=0;i--)
        {
            maxi[i] = max(maxi[i+1],ranges[i][2]);
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int profit = ranges[i][2];
            int target = ranges[i][1];
            
            int s = i+1;
            int e = n-1;
            int mid = (s+e)/2;
            int t = 0;
            
            while(s<=e)
            {
                mid = (s+e)/2;
                
                if(ranges[mid][0] >= target)
                {
                    t = maxi[mid];
                    e = mid-1;
                }
                else
                {
                    s = mid+1;
                }
            }
            
            profit += t;
            ans = max(ans,profit);
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
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends