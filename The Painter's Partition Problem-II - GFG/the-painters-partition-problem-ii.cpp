//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
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
    
    long long minTime(int arr[], int N, int K)
    {
        int low=INT_MIN;
        long long int high=0,mid,ans;
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends