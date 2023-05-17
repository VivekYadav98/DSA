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
    long long solve(int N, vector<int> &A, vector<int> &B) {
        int sum1 = 0,sum2=0;
        
        for(auto i:A)
        {
            sum1 += i;
        }
        
        for(auto i:B)
        {
            sum2 += i;
        }
        
        if(sum1 != sum2)
        {
            return -1;
        }
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        bool flag = false;
        for(int i=0;i<N;i++)
        {
            if(A[i] != B[i])
            {
                flag = true;
                break;
            }
        }
        
        if(flag == false)
        {
            return 0;
        }
        
        vector<int>temp1(N,0);
        vector<int>temp2(N,0);
        
        int x=0,y=N-1;
        int cnt1=0,cnt2=0;
        for(auto i:A)
        {
            if(i%2 == 0)
            {
                cnt1++;
                temp1[x++] = i;
            }
            else
            {
                temp1[y--] = i;
            }
        }
        
        x=0,y=N-1;
        for(auto i:B)
        {
            if(i%2 == 0)
            {
                cnt2++;
                temp2[x++] = i;
            }
            else
            {
                temp2[y--] = i;
            }
        }
        
        if(cnt1 != cnt2)
        {
            return -1;
        }
        
        long long int cnt=0;
        for(int i=0;i<N;i++)
        {
            cnt += abs(temp1[i]-temp2[i]);
        }
        
        if(cnt%2 != 0)
        {
            return -1;
        }
        
        return cnt/4;
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
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends