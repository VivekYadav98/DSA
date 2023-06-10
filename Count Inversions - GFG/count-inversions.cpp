//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int ans = 0;
    
    void merge(long long arr[],int s,int mid,int e)
    {
        long long int n1 = mid-s+1;
        long long int n2 = e-mid;
        long long int left[n1];
        long long int right[n2];
        
        for(int i=0;i<n1;i++)
        {
            left[i] = arr[s+i];
        }
        for(int i=0;i<n2;i++)
        {
            right[i] = arr[mid+1+i];
        }
        
        int i=0,j=0,k=s;
        
        while(i<n1 && j<n2)
        {
            if(left[i] <= right[j])
            {
                arr[k++] = left[i++];
            }
            else
            {
                ans += n1-i;
                arr[k++] = right[j++];
            }
        }
        
        while(i<n1)
        {
            arr[k++] = left[i++];
        }
        while(j<n2)
        {
            arr[k++] = right[j++];
        }
    }
    
    void mergeSort(long long arr[],int s,int e)
    {
        if(s<e)
        {
            int mid = s+(e-s)/2;
            mergeSort(arr,s,mid);
            mergeSort(arr,mid+1,e);
            merge(arr,s,mid,e);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long int s=0,e=N-1;
        mergeSort(arr,s,e);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends