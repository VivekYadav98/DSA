//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
          vector<vector<int>>ans;
          bool flag = false;
          
          for(int i=0;i<intervals.size();i++)
          {
              if(flag == false && newEvent[0] <= intervals[i][0])
              {
                  ans.push_back(newEvent);
                  flag = true;
                  i--;
              }
              else if(flag == false && intervals[i][0] <= newEvent[0] && intervals[i][1] <= newEvent[0])
              {
                  ans.push_back(intervals[i]);
              }
              else if(flag == false && intervals[i][0] <= newEvent[0] && intervals[i][1] >= newEvent[1])
              {
                  flag = true;
                  ans.push_back(intervals[i]);
              }
              else if(flag == false && newEvent[1] <= intervals[i][0])
              {
                  ans.push_back(newEvent);
                  flag = true;
                  i--;
              }
              else
              {
                  ans.push_back(intervals[i]);
              }
          }
         
         if(flag == false)
         {
             ans.push_back(newEvent);
         }
         
         
        int res = 0;
        for(int i=1;i<ans.size();i++)
        {
           if(ans[res][1] >= ans[i][0])
             {
                 ans[res][0] = min(ans[res][0],ans[i][0]);
                 ans[res][1] = max(ans[res][1],ans[i][1]);
             }
             else
             {
                 res++;
                 ans[res] = ans[i];
             }
        }

        vector<vector<int>>result;
        for(int i=0;i<=res;i++)
        {
            result.push_back(ans[i]);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends