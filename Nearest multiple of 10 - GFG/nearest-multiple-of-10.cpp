//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    string roundToNearest(string N) 
    { 
        int n = N.length();
        int r = N[n-1] - '0';
        if(r<=5)
        {
            N[n-1] = 0 +'0';
            return N;
        }
        else
        {
            N[n-1] = 0 +'0';
            int carry = 1;
            for(int i=n-2;i>=0;i--)
            {
                int num = N[i]-'0';
                num = num+carry;
                int digit = num%10;
                carry = num/10;
                N[i] = digit+'0';
            }
            
            if(carry != 0)
            {
                N='1'+N;
            }
            return N;
        }
    }  

};

//{ Driver Code Starts.

int main() {
    
    int t;cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout << ob.roundToNearest(s) << endl;
    }
    
	return 0;
}
// } Driver Code Ends