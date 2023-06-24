//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
        vector<vector<int>>arr;
        int s = newEvent[0];
        int e = newEvent[1];
        
        bool flag = true;
        for(int i=0;i<intervals.size();i++)
        {
            if(s <= intervals[i][0] && flag == true)
            {
                flag = false;
                arr.push_back(newEvent);
                arr.push_back(intervals[i]);
            }
            else
            {
                arr.push_back(intervals[i]);
            }
        }
        
        if(flag)
        {
            arr.push_back(newEvent);
        }
        
        int res = 0;
        vector<vector<int>>ans;

        for(int i=1;i<arr.size();i++)
        {
            if(arr[res][1] >= arr[i][0])
            {
                arr[res][0] = min(arr[res][0] , arr[i][0]);
                arr[res][1] = max(arr[res][1] , arr[i][1]);
            }
            else
            {
                res++;
                arr[res] = arr[i];
            }
        }

        for(int i=0;i<=res;i++)
        {
            ans.push_back(arr[i]);
        }
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