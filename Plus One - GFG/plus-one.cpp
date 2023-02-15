//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> digits ,int N) {
         vector<int>num = {1};

        int i=digits.size()-1;
        int j=num.size()-1;

        int carry = 0;
        vector<int>ans;
        while(i>=0 && j>=0)
        {
            int sum = digits[i] + num[j];
            sum += carry;

            int digit = sum%10;
            ans.push_back(digit);
            carry = sum/10;
            i--;
            j--;
        }

        while(i>=0)
        {
           int sum = digits[i];
            sum += carry;

            int digit = sum%10;
            ans.push_back(digit);
            carry = sum/10;
            i--; 
        }

        while(j>=0)
        {
            int sum = num[j];
            sum += carry;

            int digit = sum%10;
            ans.push_back(digit);
            carry = sum/10;
            j--;
        }

        while(carry>0)
        {
            int sum = carry;
            int digit = sum%10;
            ans.push_back(digit);
            carry = sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends