//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        if(str.length()%2 != 0)
        {
            return -1;
        }
        
       int ans = 0;
       for(int i=0;i<str.length();i++)
       {
           if(str[i] == '0')
           {
               str[i] = -1 + '0';
           }
       }
       
       int num = 0;
       for(int i=1;i<str.length();i++)
       {
           char ch1 = str[i-1];
           int num1 = ch1 - '0';
           int num2 = str[i] - '0';
            num = num1+num2;
           str[i] = num + '0';
           
           if(num == 0)
           {
               ans++;
           }
       }
       
       if(num != 0)
       {
           return -1;
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends