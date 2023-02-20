//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int n, int x)
    {
        if(x<arr[0])
        {
            return 0;
        }

        int s=0,e=n-1;
        int i=0,j=0;
        int mid = 0;
        
        while(s<=e)
        {
            mid = e + (s-e)/2;
            
            if(arr[mid] == x)
            {
                return mid;
            }
            else if(mid+1<n && arr[mid]<x && arr[mid+1]>x)
            {
                return mid+1;
            }
            else if(arr[mid]<x)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
        return mid+1;
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
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends