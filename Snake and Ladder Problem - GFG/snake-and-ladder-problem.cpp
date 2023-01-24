//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 int minThrow(int N, int arr[]){
       unordered_map<int,int>m;
       for(int i =0;i<2*N-1;i+=2)
       {
            m[arr[i]] = arr[i+1] ;
       }
       
       int steps = 0;
       queue<int>q;
       q.push(1);
       vector<bool>visited(31,false);
       visited[1] = true;
       
       while(!q.empty())
       {
           int size = q.size();
           
           for(int i=0;i<size;i++)
           {
               int x = q.front();
               q.pop();
               
               if(x == 30)
               {
                   return steps;
               }
                   
               for(int k=1;k<=6;k++)
               {
                   if(x+k > 30)
                   {
                       break;
                   }
                   
                   if(!visited[x+k])
                   {
                       visited[x+k] = true;
                       if(m.find(k+x) == m.end())
                       {
                           q.push(k+x);
                       }
                       else
                       {
                           q.push(m[k+x]);
                       }
                   }
               }
           }
           steps++;
       }
       return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends