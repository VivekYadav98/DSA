//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        int s=0,e=n-1;
        int ans = INT_MAX;
        while(s<=e)
        {
            int mid = e+(s-e)/2;
            ans = min(ans,nums[mid]);

            if(nums[mid] >= nums[s])
            {
                ans = min(ans,nums[s]);
                s = mid+1;
            }
            else
            {
                ans = min(ans,nums[e]);
                e = mid-1;
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
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends