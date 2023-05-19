//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isHappy(int n){
         unordered_set<int>s;
        while(n != 1)
        {
            if(s.find(n) != s.end())
            {
                return false;
            }
            s.insert(n);
            int sum = 0;

            while(n>0)
            {
                int r = n%10;
                sum += r*r;
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends