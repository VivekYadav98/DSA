//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s,s1;
    public:
    
       int getMin()
       {
           if(s1.empty())
           {
               return -1;
           }
           return s1.top();
       }
       
       int pop()
       {
           if(s.empty())
           {
               return -1;
           }
           
           int x = s.top();
           s.pop();
           
           if(!s1.empty() && x == s1.top())
           {
               s1.pop();
           }
           return x;
       }
       
       void push(int x)
       {
           s.push(x);
           
           if(s1.empty())
           {
               s1.push(x);
           }
           else if(x <= s1.top())
           {
               s1.push(x);
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends