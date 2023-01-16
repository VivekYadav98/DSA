//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
static bool cmp(vector<int>a,vector<int>b)
{
    return (a[0] < b[0]);
}


    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end());
         
         int res = 0;
         for(int i=1;i<intervals.size();i++)
         {
             if(intervals[res][1] >= intervals[i][0])
             {
                 intervals[res][0] = min(intervals[res][0],intervals[i][0]);
                 intervals[res][1] = max(intervals[res][1],intervals[i][1]);
             }
             else
             {
                 res++;
                 intervals[res] = intervals[i];
             }
         }
         vector<vector<int>>ans;
         for(int i=0;i<=res;i++)
         {
             ans.push_back(intervals[i]);
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends