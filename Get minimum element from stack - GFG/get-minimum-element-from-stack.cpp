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
    stack<int> st;
    public:

    /*returns min element from stack*/
       int getMin(){
            if(st.empty())
            {
                return -1;
            }
            return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(!st.empty())
            {
                if(st.top() >= minEle)
                {
                    int x = st.top();
                    st.pop();
                    return x;
                }
                else
                {
                    int x = minEle;
                    minEle = 2*minEle-st.top();
                    st.pop();
                    return x;
                }
            }
            else
            {
                return -1;
            }
       }
       
       /*push element x into the stack*/
       void push(int val){
            if(st.empty())
            {
                st.push(val);
                minEle = val;
            }
            else
            {
                if(val >= minEle)
                {
                    st.push(val);
                }
                else
                {
                    st.push(2*val-minEle);
                    minEle = val;
                }
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