//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  long long int merge(long long arr[],long long l,long long r,long long mid)
  {
       long long int n1 = mid-l+1;
      long long int n2 = r-mid;
      long long int left[n1];
      long long int right[n2];
      
      for(int i=0;i<n1;i++)
      {
          left[i] = arr[l+i];
      }
      
      for(int i=0;i<n2;i++)
      {
          right[i] = arr[mid+1+i];
      }
      
      long long int i=0,j=0,k=l,res=0;
      
      while(i<n1 && j<n2)
      {
          if(left[i] <= right[j])
          {
              arr[k] = left[i];
              i++;
          }
          else
          {
              arr[k] = right[j];
              j++;
              res += (n1-i);
          }
          k++;
      }
      
      while(i<n1)
      {
        arr[k] = left[i];
              i++;
              k++;
      }
      
      while(j<n2)
      {
         arr[k] = right[j];
              j++;
              k++;
      }
      return res;
  }
  long long int inversion(long long arr[],long long l,long long r)
  {
      long long int res=0;
      
      if(l < r) 
      {
         long long int mid = l + (r-l)/2;
         res += inversion(arr,l,mid);
         res += inversion(arr,mid+1,r);
         res += merge(arr,l,r,mid);
      }
      return res;
  }
  
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
      return inversion(arr,0,N-1);
        
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