//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    static bool mycomp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
        
        
        
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
        
        
    }
    void sortBySetBitCount(int arr[], int n)
    {
        
        vector<pair<int,pair<int,int>>>a;
        
        for(int j=0;j<n;j++){
         int y =0;
         int b= arr[j];
         for(int i=31;i>=0;i--){
             int t = 1<<i;
             if((t&b)!=0){
                 y++;
             }
         }
         
         a.push_back({y,{j,arr[j]}});
        }
        sort(a.begin(),a.end(),mycomp);
        for(int i=0;i<n;i++){
            arr[i]=a[i].second.second;
        }
        
        
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends