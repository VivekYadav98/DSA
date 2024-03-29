//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int s=0,e=n-1,mid;
        
        while(s<=e)
        {
            mid = (s+e)/2;
            
            if(arr[mid] == arr[mid+1])
            {
                mid++;
            }
            else if(arr[mid] != arr[mid-1])
            {
                return arr[mid];
            }
            
            if((mid-s+1)%2 == 0)
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
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends