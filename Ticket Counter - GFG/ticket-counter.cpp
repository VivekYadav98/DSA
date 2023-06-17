//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        deque<int>dq;
        for(int i=1;i<=N;i++)
        {
            dq.push_back(i);
        }
        
        bool flag = true;
        while(dq.size() > 1)
        {
            int m=K;
            while(m>0 && flag == true && dq.size() > 1)
            {
                dq.pop_front();
                m--;
            }
            
            if(flag == true)
            {
                flag = false;
                continue;
            }
            
            m=K;
            while(m>0 && flag == false && dq.size() > 1)
            {
                dq.pop_back();
                m--;
            }
            
            if(flag == false)
            {
                flag = true;
                continue;
            }
        }
        
        return dq.front();
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