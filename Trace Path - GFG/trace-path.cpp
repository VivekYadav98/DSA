//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int t_left=0,t_right=0,t_up=0,t_down=0;
        int curr_h=0,curr_v=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == 'L')
            {
                curr_h++;
                t_left = max(t_left,curr_h);
            }
            else if(s[i] == 'R')
            {
                curr_h--;
                t_right = min(t_right,curr_h);
            }
            else if(s[i] == 'U')
            {
                curr_v++;
                t_up = max(t_up,curr_v);
            }
            else if(s[i] == 'D')
            {
                curr_v--;
                t_down = min(t_down,curr_v);
            }
        }
        
        if((t_left-t_right+1 <=m) && (t_up-t_down+1 <=n))
        {
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends