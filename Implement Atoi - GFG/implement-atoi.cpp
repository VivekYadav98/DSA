//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
       int ans = 0;
       bool flag = false;
       for(int i=0;i<str.length();i++)
       {
           if(str[i] == '-' && i != 0)
           {
               return -1;
           }
           
          if(str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' &&
          str[i] != '5'
          && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '-')
          {
              return -1;
          }
          else
          {
              if(str[i] == '-')
              {
                  flag = !flag;
              }
              else
              {
                ans = ans*10 + str[i]-'0';
              }
          }
       }
       
       if(flag == true)
       {
           return -ans;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends