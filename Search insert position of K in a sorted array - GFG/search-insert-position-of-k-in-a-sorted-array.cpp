//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int s=0,e=N-1,mid;
        
        while(s<=e)
        {
            mid = s+(e-s)/2;
            
            if(Arr[mid] == k)
            {
                return mid;
            }
            else if(mid == 0 && k<=Arr[mid])
            {
                return 0;
            }
            else if(mid == N-1 && k>=Arr[mid])
            {
                return N;
            }
            else if(k > Arr[mid-1] && k< Arr[mid])
            {
                return mid;
            }
            else if(k>Arr[mid] && k<Arr[mid+1])
            {
                return mid+1;
            }
            else if(k > Arr[mid])
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }
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