//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        int cnt = 0;
        int x = str.length();
        string temp = str;
        reverse(str.begin(),str.end());
        string s = str + temp;
        int i=0,j=str.length();
        
        while(i<j && i<x && j<s.length())
        {
            if(s[i] == s[j])
            {
               int m=i,n=j;
               bool flag = true;
               while(i<j && i<x && j<s.length())
               {
                   if(s[i] != s[j])
                   {
                       flag = false;
                       break;
                   }
                   i++;
                   j++;
               }
               
               if(flag == false)
               {
                   cnt++;
                   i = m;
                   j = n;
                   i++;
               }
            }
            else
            {
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends