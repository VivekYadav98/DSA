//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        int i=n-1;
        int j=m-1;

        int carry = 0;
        string ans = "";
        while(i>=0 && j>=0)
        {
            int sum = a[i] + b[j];
            sum += carry;

            int digit = sum%10;
            ans += digit + '0';
            carry = sum/10;
            i--;
            j--;
        }

        while(i>=0)
        {
           int sum = a[i];
            sum += carry;

            int digit = sum%10;
            ans += digit + '0';
            carry = sum/10;
            i--; 
        }

        while(j>=0)
        {
            int sum = b[j];
            sum += carry;

            int digit = sum%10;
            ans += digit + '0';
            carry = sum/10;
            j--;
        }

        while(carry>0)
        {
            int sum = carry;
            int digit = sum%10;
            ans += digit + '0';
            carry = sum/10;
        }
        
        while(ans.back() == '0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends