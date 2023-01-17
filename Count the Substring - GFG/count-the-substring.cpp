//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  using ll = long long int;
   long long inversion = 0;
  void merge(vector<long long>&arr,int low,int mid,int high)
   {
       long long n1 = (mid-low)+1;
       long long n2 = high-mid;
       vector<long long>left(n1);
       vector<long long>right(n2);
       
       for(int i=0;i<n1;i++)
       {
           left[i] = arr[low+i];
       }
       
       for(int i=0;i<n2;i++)
       {
           right[i] = arr[mid+1+i];
       }
       
       int i=0,j=0,k=low;
       
       while(i<n1 && j<n2)
       {
           if(left[i]<=right[j])
           {
               arr[k] = left[i];
               i++;
               k++;
           }
           else
           {
               arr[k] = right[j];
               inversion += (n1-i);
               j++;
               k++;
           }
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
   }
   
   
   void mergesort(vector<long long>& arr,int low,int high)
   {
       if(low<high)
       {
           int mid = low + (high-low)/2;
            mergesort(arr,low,mid);
            mergesort(arr,mid+1,high);
            merge(arr,low,mid,high);
       }
   }


   long long countSubstring(string s){
       int n = s.size();

      vector<long long> v(n);

      long long ans = 0;

      for(int i = 0; i < n; i ++)
      {
          if(s[i] == '1')
          {
              v[i] = 1;
          }
          else
          {
              v[i] = -1;
          }

          if(i > 0) 
          {
              v[i] += v[i - 1];
          }

          if(v[i]>0)
          {
              ans ++;
          }
      }

      reverse(v.begin(), v.end());

      mergesort(v, 0, n - 1);

      ans += inversion;

      return ans;

  }

};



//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends