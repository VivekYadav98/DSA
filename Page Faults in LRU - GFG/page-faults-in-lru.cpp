//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_map<int,int>m;
        int ans = 0;
        for(int i=0;i<N;i++)
        {
           if(m.size() < C)
           {
               if(m.find(pages[i]) != m.end())
               {
                   m.erase(pages[i]);
                   m[pages[i]] = i;
               }
               else
               {
                   ans++;
                   m[pages[i]] = i;
               }
           }
           else
           {
               if(m.find(pages[i]) != m.end())
               {
                   m.erase(pages[i]);
                   m[pages[i]] = i;
               }
               else
               {
                   ans++;
                   int mini = INT_MAX;
                   for(auto it:m)
                   {
                       mini = min(mini,it.second);
                   }
                   
                   m.erase(pages[mini]);
                   m[pages[i]] = i;
               }
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
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends