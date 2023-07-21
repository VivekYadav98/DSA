//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int temp,int arr[],int n,int k)
    {
        int cnt=0,sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            
            if(sum>temp)
            {
                cnt++;
                sum = arr[i];
            }
        }
        
        if(sum <= temp)
        {
            cnt++;
        }
        
        if(cnt <= k)
        {
            return true;
        }
        
        return false;
    }
    
    int splitArray(int arr[] ,int N, int K) {
        int low=INT_MIN,high=0,mid,ans;
        for(int i=0;i<N;i++)
        {
            low = max(low,arr[i]);
            high += arr[i];
        }
        
        while(low<=high)
        {
            mid = (low+high)/2;
            
            if(isPossible(mid,arr,N,K))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends