//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&prices){
       int n = prices.size();
        vector<vector<int>>next(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    long profit = 0;
                    if(buy)
                    {
                        profit = max(-prices[ind] + next[0][cap] , 0 + next[1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind] + next[1][cap-1] , 0 + next[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
                next = curr;
            }
        }

        return next[1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends