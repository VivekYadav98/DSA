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
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<int>leaf(N+1,0);
        
        for(int i=1;i<N;i++)
        {
            leaf[P[i]]++;
        }
        
        long long ans = INT_MIN;
        for(int i=1;i<=N;i++)
        {
            if(leaf[i] == 0)
            {
                int j = i;
                long long temp = 0;
                
                while(j != -1)
                {
                    temp += A[j-1];
                    j = P[j-1];
                    ans = max(ans,temp);
                    temp *= -1;
                }
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
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends