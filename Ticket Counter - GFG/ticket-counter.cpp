//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int ans = 1;
        bool flag = true;
        
        int i=1,j=N,cnt=1;
        while(i<=N && j>=1 && cnt<N)
        {
            int cnt1 = 0;
            while(i<=N && cnt1<K && cnt<N)
            {
                cnt1++;
                i++;
                cnt++;
                
                ans = i;
            }
            
            int cnt2 = 0;
            while(j>=1 && cnt2<K && cnt<N)
            {
                cnt2++;
                j--;
                cnt++;
                ans = j;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends