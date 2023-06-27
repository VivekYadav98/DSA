//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        long ans=0,i=0,j=0,k=-1;
        int maxi=0;
        
        while(j<n)
        {
            maxi = max(maxi,a[j]);
            
            if(maxi>R)
            {
                j++;
                maxi=0;
                i=j;
                continue;
            }
            
            if(maxi<L)
            {
                j++;
                continue;
            }
            
            if(a[j]<L)
            {
                if(k == -1)
                {
                    k = j;
                }
                
                ans += j-i;
                
                if(k != -1)
                {
                  ans -= j-k;
                }
            }
            else
            {
                k = -1;
                ans += j-i+1;
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends