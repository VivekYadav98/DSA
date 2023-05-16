//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        for(int i=0;i<N;i++)
        {
            if(S[i] == '0')
            {
                int k = X;
                int m=i,n=i;
                bool flag = false;
                
                while(k>0)
                {
                    m++;
                    n--;
                    
                    if((m<S.length() && S[m] == '1') || (n>=0 && S[n] == '1'))
                    {
                        flag = true;
                        break;
                    }
                    k--;
                }
                
                if(flag == false)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends