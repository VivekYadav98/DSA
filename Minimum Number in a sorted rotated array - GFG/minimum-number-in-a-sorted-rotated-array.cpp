//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int nums[], int low, int high)
    {
        int s=0,e=high,mid;
        int ans = INT_MAX;

        while(s<=e)
        {
            mid = e+(s-e)/2;

            if(nums[s] <= nums[mid])
            {
                ans = min(ans,nums[s]);
                s = mid+1;
            }
            else
            {
                ans = min(ans,nums[mid]);
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends