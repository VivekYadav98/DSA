//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) {
       for(int i=1;i<N;i++)
       {
           arr[i] += arr[i-1];
       }
       
       vector<int>factors;
       int num = arr[N-1];
       for(int i=1;i*i<=num;i++)
       {
           if(num%i == 0)
           {
               factors.push_back(i);
               if(i != num/i)
               {
                   factors.push_back(num/i);
               }
           }
       }
       
    //   sort(factors.begin(),factors.end(),greater<int>{});
       
       int ans = 1;
       for(auto it:factors)
       {
           int count = 0;
           for(int i=0;i<N;i++)
           {
               if(arr[i]%it == 0)
               {
                   count++;
               }
           }
           
           if(count>=K)
           {
               ans = max(ans,it);
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends