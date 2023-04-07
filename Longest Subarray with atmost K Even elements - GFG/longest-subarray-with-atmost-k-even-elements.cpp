#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> arr[i];
	    }
	    
	    int cnt = 0;
	    int ans = 0;
	    int i=0,j=0;
	    
	    while(j<n)
	    {
	        if(arr[j]%2 == 0)
	        {
	            cnt++;
	        }
	        
	        if(cnt <= k)
	        {
	            ans = max(ans,j-i+1);
	            j++;
	        }
	        else if(cnt > k)
	        {
	            while(cnt > k)
	            {
	                if(arr[i]%2 == 0)
	                {
	                    cnt--;
	                }
	                i++;
	            }
	            j++;
	        }
	    }
	    
	    if(ans == 0)
	    {
	      ans = n;
	    }
	    
	    cout << ans << endl;
	}
	return 0;
}