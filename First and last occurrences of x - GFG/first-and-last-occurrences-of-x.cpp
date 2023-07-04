//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int indFloor=-1,indCeil=-1;
    bool flag = false;
    int s=0,e=n-1,mid;
    
    while(s<=e)
    {
        mid = s+(e-s)/2;
        
        if(arr[mid] == x)
        {
            indFloor = mid;
            e = mid-1;
        }
        else if(arr[mid] < x)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    
    s=0,e=n-1,mid;
    
    while(s<=e)
    {
        mid = s+(e-s)/2;
        
        if(arr[mid] == x)
        {
            indCeil = mid;
            s = mid+1;
        }
        else if(arr[mid] < x)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    
    if(indFloor == -1)
    {
        return {-1,-1};
    }
    return {indFloor,indCeil};
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends