//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
       int ans= 0;
       for(int i=0;i<S.length();i++)
       {
           int lowerCase = 0;
           int upperCase = 0;
           if(islower(S[i]))
           {
               lowerCase++;
           }
           else
           {
               upperCase++;
           }
           
           for(int j=i+1;j<S.length();j++)
           {
               if(islower(S[j]))
               {
                   lowerCase++;
               }
               else
               {
                   upperCase++;
               }
               
               if(lowerCase == upperCase)
               {
                   ans++;
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends