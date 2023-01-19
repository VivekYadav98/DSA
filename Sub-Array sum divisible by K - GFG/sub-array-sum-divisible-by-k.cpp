//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long K)
	{
	     long long ans = 0;
        unordered_map<long long,long long>m;
        long long sum=0,remainder=0;
        m[remainder]++;
        
        for(long long i=0;i<N;i++)
        {
            sum += arr[i];
            remainder = sum%K;
            
            if(remainder<0)
            {
                remainder += K;
            }
            
            if(m.find(remainder) != m.end())
            {
                ans += m[remainder];
            }
             m[remainder]++;
        }
        return ans;
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
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends