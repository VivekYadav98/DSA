//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int pages,int arr[],int n,int m)
    {
        int cnt = 0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            
            if(sum > pages)
            {
                cnt++;
                sum = arr[i];
            }
        }
        
        if(sum < pages)
        {
            cnt++;
        }
            
        if(cnt <= m)
        {
            return true;
        }
        return false;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N)
        {
            return -1;
        }
        
        int low=INT_MIN,high=0;
        for(int i=0;i<N;i++)
        {
            low = max(low,A[i]);
            high += A[i];
        }
        
        int ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(isPossible(mid,A,N,M))
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

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends