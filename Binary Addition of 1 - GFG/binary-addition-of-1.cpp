//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string binaryAdd(int n, string a){
        string b = "1";
        int carry = 0;
        int i=a.length()-1;
        int j=b.length()-1;
        string ans = "";
        while(i>=0 && j>=0)
        {
            int sum = a[i]-'0' + b[j]-'0';
            sum += carry;

            if(sum == 2)
            {
                ans += '0';
                carry = 1;
            }
            else if(sum > 2)
            {
                ans += '1';
                carry = 1;
            }
            else if(sum <= 1)
            {
                ans += sum + '0';
                carry = 0;
            }
            i--;
            j--;
        }

        while(i>=0)
        {
            int sum = a[i]-'0';
            sum += carry;

             if(sum == 2)
            {
                ans += '0';
                carry = 1;
            }
            else if(sum > 2)
            {
                ans += '1';
                carry = 1;
            }
            else if(sum <= 1)
            {
                ans += sum + '0';
                carry = 0;
            }
            i--;
        }

        while(j>=0)
        {
            int sum = b[j]-'0';
            sum += carry;

             if(sum == 2)
            {
                ans += '0';
                carry = 1;
            }
             else if(sum > 2)
            {
                ans += '1';
                carry = 1;
            }
            else if(sum <= 1)
            {
                ans += sum + '0';
                carry = 0;
            }
            j--;
        }

        while(carry > 0)
        {
            int sum = carry;
            if(sum == 2)
            {
                ans += '0';
                carry = 1;
            }
             else if(sum > 2)
            {
                ans += '1';
                carry = 1;
            }
            else if(sum <= 1)
            {
                ans += sum + '0';
                carry = 0;
            }
            carry--;
        }
    
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        
        Solution ob;
        cout<<ob.binaryAdd(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends