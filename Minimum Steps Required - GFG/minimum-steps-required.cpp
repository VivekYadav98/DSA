//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int ans = 0;
    for(int i=0;i<str.length();i++)
    {
        char ch = str[i];
        i++;
        bool flag = false;
        
        while(i<str.length() && str[i] == ch)
        {
            i++;
        }
        
        while(i<str.length() && str[i] != ch)
        {
            i++;
            flag = true;
        }
        
        if(flag == true)
        {
            ans++;
        }
        i--;
    }
    return 1+ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends