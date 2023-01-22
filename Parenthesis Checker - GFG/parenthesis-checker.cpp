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
        stack<char>s;
        s.push(x[0]);
        int i=1;
        
        // if(x.length()%2 != 0)
        // {
        //     return false;
        // }
        
        while(i<x.length())
        {
            if(x[i] == '[' || x[i] == '{' || x[i] == '(')
            {
                s.push(x[i]);
            }
            else if(!s.empty())
            {
                if(x[i] == ']' && s.top() != '[')
                {
                    return false;
                }
                else if(x[i] == '}' && s.top() != '{')
                {
                    return false;
                }
                else if(x[i] == ')' && s.top() != '(')
                {
                    return false;
                }
                else
                {
                    s.pop();
                }
            }
            i++;
        }
        
        if(!s.empty())
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