//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    queue<pair<int,pair<int,int>>>q;
	    q.push({0,{KnightPos[0]-1,KnightPos[1]-1}});
	    vector<vector<int>>dist(N,vector<int>(N,INT_MAX));
	    dist[KnightPos[0]-1][KnightPos[1]-1] = 0;
	    
	    if(KnightPos[0]-1 == TargetPos[0]-1 && KnightPos[1]-1 == TargetPos[1]-1)
	    {
	        return 0;
	    }
	    
	    int dr[] = {-1,-2,-2,-1,1,2,2,1};
	    int dc[] = {-2,-1,1,2,2,1,-1,-2};
	    
	    while(!q.empty())
	    {
	        int steps = q.front().first;
	        int r = q.front().second.first;
	        int c = q.front().second.second;
	        q.pop();
	        
	        for(int i=0;i<8;i++)
	        {
	            int newr = r+dr[i];
	            int newc = c+dc[i];
	            
	            if(newr>=0 && newr<N && newc>=0 && newc<N)
	            {
	                if(steps+1 < dist[newr][newc])
	                {
	                    dist[newr][newc] = steps+1;
	                    q.push({steps+1,{newr,newc}});
	                }
	            }
	        }
	    }
	    
	    if(dist[TargetPos[0]-1][TargetPos[1]-1] == INT_MAX)
	    {
	        return -1;
	    }
	    else
	    {
	        return dist[TargetPos[0]-1][TargetPos[1]-1];
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends