//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    long int minOperations(int arr[], int N)
    {
        long long int sum=0,cnt1=0,cnt2=0,ans1=0,ans2=0;
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
        }
        
        int target = sum/N;
        for(int i=0;i<N;i++)
        {
           if(arr[i] > target)
           {
               ans1 += arr[i]-target;
               cnt1++;
           }
           else if(arr[i] < target)
           {
               ans2 += target-arr[i];
               cnt2++;
           }
        }
        
        if(ans1 != ans2)
        {
            return -1;
        }
        return ans1;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n,i;
	 cin>>n; int a[n];
	 for(i=0;i<n;i++)
	 cin>>a[i];
	 Solution obj;
	  long int ans=obj.minOperations(a,n);
	  cout<<ans<<endl;
	}
	return 0;
}


// } Driver Code Ends