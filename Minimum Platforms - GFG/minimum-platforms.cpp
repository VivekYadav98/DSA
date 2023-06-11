//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int N)
    {
    	vector<int>ans;
        
        sort(arr,arr+N);
        sort(dep,dep+N);
        
        int i=0,j=0;
        int curr=0,maxi=0,timing = 0;
        
        while(i<N && j<N)
        {
            if(arr[i] <= dep[j])
            {
                curr++;
                i++;
            }
            else
            {
                curr--;
                j++;
            }
            
            if(curr > maxi)
            {
                maxi = curr;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends