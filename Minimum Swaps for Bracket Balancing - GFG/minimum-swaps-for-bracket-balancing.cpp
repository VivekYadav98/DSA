//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int shift = 0;
        int open=0,close=0;
        int unbalanced = 0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i] == '[')
            {
                open++;
                if(unbalanced > 0)
                {
                    shift += unbalanced; 
                    unbalanced--;
                }
            }
            else
            {
                close++;
                unbalanced = close-open;
            }
        }
        return shift;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends