//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        long long ans = 0;
        int n = str.length();
        unordered_map<string,long long>m;
        int zero=0,one=0,two=0;
        
        for(int i=0;i<n;i++)
        {
            if(str[i] == '0')
            {
                zero++;
            }
            else if(str[i] == '1')
            {
                one++;
            }
            else
            {
                two++;
            }
            
            string key = to_string(one-zero) + "#" + to_string(two-one);
            if(zero == one && one == two && two == zero)
            {
                ans++;
            }
            
            if(m.find(key) != m.end())
            {
                ans += m[key];
            }
            m[key]++;
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
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends