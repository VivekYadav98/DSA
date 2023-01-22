//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPalindrome(string s)
    {
        int i=0,j=s.length()-1;
        
        while(i<=j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
//     int solveRec(string& s,int i)
//     {
//         if(i==s.size())
//         {
//             return 0;
//         }
        
//         string temp = "";
//         int minCost = INT_MAX;
        
//         for(int j=i;j<s.size();j++)
//         {
//             temp += s[j];
//             if(isPalindrome(temp))
//             {
//                 int cost = 1+solveRec(s,j+1);
//                 minCost = min(minCost,cost);
//             }
//         }
//         return minCost;
//     }
    
    int solveMem(string& s,int i,vector<int>& dp)
    {
        if(i==s.size())
        {
            return 0;
        }
        
        if(dp[i] != -1)
        {
            return dp[i];
        }
        
        string temp = "";
        int minCost = INT_MAX;
        
        for(int j=i;j<s.size();j++)
        {
            temp += s[j];
            if(isPalindrome(temp))
            {
                int cost = 1+solveMem(s,j+1,dp);
                minCost = min(minCost,cost);
            }
        }
        return dp[i] = minCost;
    }
    
    
    int palindromicPartition(string str)
    {
         vector<int>dp(str.size()+1,-1);
        return solveMem(str,0,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends