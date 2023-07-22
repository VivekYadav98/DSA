//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	 int dr[8] = {-2,-2,-1,1,2,2,1,-1};
    int dc[8] = {-1,1,2,2,1,-1,-2,-2};

    double solve(int n,int k,int row,int col,vector<vector<vector<double>>>& dp)
    {
        if(row<0 || row>=n || col<0 || col>=n)
        {
            return 0;
        }

        if(k == 0)
        {
            return 1;
        }

        if(dp[row][col][k] != -1)
        {
            return dp[row][col][k];
        }

        double sum = 0;
        for(int i=0;i<8;i++)
        {
            int newr = row+dr[i];
            int newc = col+dc[i];

            sum += solve(n,k-1,newr,newc,dp);
        }

        sum /= 8.0;
        return dp[row][col][k] = sum;
    }
	
	double findProb(int n,int row, int col, int k)
	{
	    vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return solve(n,k,row,col,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends