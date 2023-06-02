//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        int ans = 0;
        vector<int>preSum(N,0);
        preSum[0] = Arr[0];

        for(int i=1;i<N;i++)
        {
            preSum[i] = preSum[i-1] + Arr[i];
        }

        unordered_map<int,int>m;
        for(int i=0;i<N;i++)
        {
            if(preSum[i] == k)
            {
                ans++;
            }
            if(m.find(preSum[i]-k) != m.end())
            {
                ans += m[preSum[i]-k];
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
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends