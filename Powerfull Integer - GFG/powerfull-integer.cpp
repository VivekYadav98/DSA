//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        map<int,int>m;
        for(auto it:intervals)
        {
            m[it[0]]++;
            m[it[1]+1]--;
        }
        
        int ans = -1;
        int sum = 0;
        
        for(auto i:m)
        {
            sum += i.second;
            
            if(i.second < 0)
            {
                sum += abs(i.second);
                
                if(sum >= k)
                {
                    ans = i.first-1;
                }
                
                sum -= abs(i.second);
            }
           
            if(sum >= k)
            {
                ans = max(ans,i.first);
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
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends