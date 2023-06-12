//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int i=0;
        stack<char>st;
        
        while(i<x.length())
        {
            if(st.empty())
            {
                st.push(x[i]);
            }
            else if(x[i] == ')' || x[i] == ']' || x[i] == '}')
            {
                if((x[i] == ')' && st.top() != '(') || (x[i] == '}' && st.top() != '{') ||
                (x[i] == ']' && st.top() != '['))
                {
                    return false;
                }
                
                st.pop();
            }
            else
            {
                st.push(x[i]);
            }
            i++;
        }
        
        if(!st.empty())
        {
            return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends