//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        unordered_map<char,char>m1;
        unordered_map<char,int>m2;
        int i=0,j=0;
        
        while(i<str1.length() && j<str2.length())
        {
            if(m1.find(str1[i]) != m1.end())
            {
                if(m1[str1[i]] != str2[j])
                {
                    return false;
                }
            }
            else if(m2.find(str2[j]) != m2.end())
            {
                return false;
            }
            
            m1[str1[i]] = str2[j];
            m2[str2[j]]++;    
            i++;
            j++;
        }
        
        if(i != str1.length() || j != str2.length())
        {
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends