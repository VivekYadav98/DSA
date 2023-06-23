//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
      int ans = 0;
      
      for(int i=0;i<n;i++)
      {
          string s = arr[i];
          int ind1=0,ind2=0,cnt=0;
          
          while(ind1<s.length() && ind2<str.length() && cnt<k)
          {
              if(s[ind1] == str[ind2])
              {
                  ind1++;
                  ind2++;
                  cnt++;
              }
              else
              {
                  break;
              }
          }
          
          if(ind2 == k)
          {
              ans++;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends