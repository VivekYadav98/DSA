//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        int n = N;
        int x = 0;
        int num = 1;
        while(N & 1 == 1)
        {
            N = N>>1;
            x++;
        }
        
        num = 1<<x;
        if(num > n)
        {
            return n;
        }
        int ans = n | num;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends