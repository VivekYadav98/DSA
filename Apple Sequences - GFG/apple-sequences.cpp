//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int ans = 0;
        int i=0,j=0;
        
        while(j<n)
        {
            if(arr[j] == 'O' && m != 0)
            {
                ans = max(ans,j-i+1);
                m--;
                j++;
            }
            else if(arr[j] == 'A')
            {
                ans = max(ans,j-i+1);
                j++;
            }
            else if(arr[j] == 'O' && m == 0)
            {
                while(arr[i] == 'A')
                {
                    i++;
                }
                i++;
                m++;
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends