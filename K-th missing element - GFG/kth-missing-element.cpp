//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int arr[], int n, int k)
{
    int cnt = 0;
    int i=1;
    
    while(i<n)
    {
        while(arr[i-1]+1 != arr[i] && cnt<k)
        {
            arr[i-1]++;
            cnt++;
        }
        
        if(cnt == k)
        {
            return arr[i-1];
        }
        i++;
    }
    return -1;
}