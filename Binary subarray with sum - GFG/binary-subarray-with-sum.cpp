//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int N, int target){
       int ans = 0;
       vector<int>preSum(N,0);
       preSum[0] = arr[0];
       for(int i=1;i<N;i++)
       {
           preSum[i] = preSum[i-1] + arr[i];
       }
       
       unordered_map<int,int>m;
       for(int i=0;i<N;i++)
       {
           if(preSum[i] == target)
           {
               ans++;
           }
           
           if(m.find(preSum[i]-target) != m.end())
           {
               ans += m[preSum[i]-target];
           }
           
           m[preSum[i]]++;
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends