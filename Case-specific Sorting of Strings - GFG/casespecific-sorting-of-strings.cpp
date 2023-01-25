//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
       string ans = "";
       string temp = str;
       sort(str.begin(),str.end());
       string lower =  "";
       string capital = "";
       
       for(int i=0;i<n;i++)
       {
           if(islower(str[i]))
           {
               lower += str[i];
           }
           else
           {
               capital += str[i];
           }
       }
       
       int j=0,k=0;
       for(int i=0;i<n;i++)
       {
           if(islower(temp[i]))
           {
               ans += lower[j];
               j++;
           }
           else
           {
               ans += capital[k];
               k++;
           }
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends