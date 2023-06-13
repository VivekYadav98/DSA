//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        vector<int>ans;
        stack<int>st;
        
        int i=0;
        while(i<N)
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
            }
            else
            {
               if(asteroids[i]<0 && st.top()>0)
               {
                   int x = abs(asteroids[i]);
                   int y = st.top();
                   
                   if(x>y)
                   {
                       while(!st.empty() && asteroids[i]<0 && st.top()>0 && abs(asteroids[i]) > st.top())
                       {
                           st.pop();
                       }
                       
                       if(!st.empty() && asteroids[i]<0 && st.top()>0 && abs(asteroids[i]) == st.top())
                       {
                           st.pop();
                       }
                       else if(!st.empty() && asteroids[i]<0 && st.top()>0 && abs(asteroids[i]) < st.top())
                       {
                           i++;
                          continue;
                       }
                       else
                       {
                           st.push(asteroids[i]);
                       }
                   }
                   else if(x == y)
                   {
                       st.pop();
                   }
               }
               else
               {
                   st.push(asteroids[i]);
               }
            }
            i++;
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends