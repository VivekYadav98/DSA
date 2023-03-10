//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int weights[], int N, int days) {
        long long s=1,e=1e14,mid=s+(e-s)/2;
        long long daysCnt = 0;

        while(s<=e)
        {
            int sum=0;
            for(int i=0;i<N;i++)
            {
                if(weights[i] > mid)
                {
                    daysCnt = days+1;
                }

                sum += weights[i];
                if(sum > mid)
                {
                    daysCnt++;
                    sum = weights[i];
                }
            }

            if(sum != 0)
            {
                daysCnt++;
            }

            if(daysCnt <= days)
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
            mid=s+(e-s)/2;
            daysCnt = 0;
        }
        return mid;
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