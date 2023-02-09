#include <iostream>
#include<bits/stdc++.h>
using namespace std;

    void solve(int ind,int k,int arr[],int sum,int& ans)
	{
	    if(k == 0)
	    {
	        ans += sum;
	        return;
	    }
	    if(ind<0)
	    {
	        return;
	    }
	    
	    solve(ind-1,k,arr,sum,ans);
	    solve(ind-1,k-1,arr,sum+arr[ind],ans);
	}

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
	    
	    int ans = 0;
        solve(n-1,k,arr,0,ans);
        cout << ans << endl;
	}
	return 0;
}