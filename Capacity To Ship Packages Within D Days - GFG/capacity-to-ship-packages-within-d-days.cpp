//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        int low = 1,high=INT_MAX,mid,ans=0,maxi=INT_MIN;
        for(int i=0;i<N;i++)
        {
            
            maxi = max(maxi,arr[i]);
        }
        
        while(low<=high)
        {
            mid = (low+high)/2;
            
            if(mid<maxi)
            {
                low = mid+1;
                continue;
            }
            
            int sum=0,days=1;
            for(int i=0;i<N;i++)
            {
                sum += arr[i];
                
                if(sum > mid)
                {
                    days++;
                    sum = arr[i];
                }
            }
            
            if(days <= D)
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends