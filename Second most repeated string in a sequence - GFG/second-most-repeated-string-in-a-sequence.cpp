//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        
        int count1 = 0;
        int count2 = 0;
        string temp = "";
        string ans = "";
        
        for(auto i:m)
        {
            if(i.second > count1)
            {
                count1 = i.second;
                temp = i.first;
            }
        }
        
        for(auto i:m)
        {
            if(i.second > count2 && i.first != temp)
            {
                count2 = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends