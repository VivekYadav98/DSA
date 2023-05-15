//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
       int ans = 0;
       bool flag = false;
       
       for(int i=0;i<n;i++)
       {
           while(arr[i] != 0)
           {
               i++;
           }
           
           if(i==0 && arr[i] == 0)
           {
               while(arr[i] == 0)
               {
                   i++;
               }
           }
           
           if(i<n && arr[i] == 0)
           {
               flag = true;
               ans++;
               
               while(arr[i] == 0)
               {
                   i++;
               }
               i--;
           }
       }
       
       if(arr[n-1] == 0)
       {
           return ans;
       }
       
       if(flag == false)
       {
           return -1;
       }
       
       return ans+1;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends