//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        unordered_map<string,pair<int,int>>m;
        string ans = "";
        int index = INT_MIN;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            string s = arr[i];
            if(m.find(s) == m.end())
            {
                m[s].first = i;
            }
            m[s].second++;
            
            if(maxi < m[s].second)
            {
                index = m[s].first;
                maxi = m[s].second;
                ans = s;
            }
            else if(maxi == m[s].second &&  m[s].first > index)
            {
                index = m[s].first;
                maxi = m[s].second;
                ans = s;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends