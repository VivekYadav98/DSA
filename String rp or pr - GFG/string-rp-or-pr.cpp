//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string s){
      long long ans = 0;
      
      if(X>Y)
      {
          stack<char>st;
          int i=0;
          long long pr=0,rp=0;
          string temp = "";
          while(i<s.length())
          {
              if(st.empty())
              {
                  st.push(s[i]);
              }
              else if(st.top() == 'p' && s[i] == 'r')
              {
                  if(st.top()=='p'&& s[i]=='r')
                  {
                      pr++;
                      st.pop();
                  }
              }
              else
              {
                  st.push(s[i]);
              }
              i++;
          }
          
          while(!st.empty())
          {
              temp += st.top();
              st.pop();
          }
          
          reverse(temp.begin(),temp.end());
          i = 0;
           while(i<temp.length())
          {
              if(st.empty())
              {
                  st.push(temp[i]);
              }
              else if(st.top() == 'r' && temp[i] == 'p')
              {
                  rp++;
                  st.pop();
              }
              else if(st.top() == 'p' && temp[i] == 'r')
              {
                  pr++;
                  st.pop();
              }
              else
              {
                  st.push(temp[i]);
              }
              i++;
          }
          
          ans = pr*X + rp*Y;
      }
      else
      {
          stack<char>st;
          int i=0;
          long long pr=0,rp=0;
          string temp = "";
          while(i<s.length())
          {
              if(st.empty())
              {
                  st.push(s[i]);
              }
              else if(st.top() == 'r' && s[i] == 'p')
              {
                  if(st.top()=='r'&& s[i]=='p')
                  {
                      rp++;
                      st.pop();
                  }
              }
              else
              {
                  st.push(s[i]);
              }
              i++;
          }
          
          while(!st.empty())
          {
              temp += st.top();
              st.pop();
          }
          
          reverse(temp.begin(),temp.end());
          i = 0;
           while(i<temp.length())
          {
              if(st.empty())
              {
                  st.push(temp[i]);
              }
              else if(st.top() == 'r' && temp[i] == 'p')
              {
                  rp++;
                  st.pop();
              }
              else if(st.top() == 'p' && temp[i] == 'r')
              {
                  pr++;
                  st.pop();
              }
              else
              {
                  st.push(temp[i]);
              }
              i++;
          }
          
          ans = pr*X + rp*Y;
      }
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends