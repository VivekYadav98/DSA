//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        sort(A,A+N);
        int ans=INT_MAX,sum=0;
        for(int k=0;k<N;k++)
        {
            int i=k+1,j=N-1;
            while(i<j)
            {
                sum = A[i]+A[j]+A[k];
                
                if(sum>X)
                {
                    j--;
                }
                else if(sum<X)
                {
                    i++;
                }
                else
                {
                    return sum;
                }
                
                if(abs(X-sum) < abs(X-ans))
                {
                    ans = sum;
                }
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends