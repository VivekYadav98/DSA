//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int n, int m, int k)
    {
         vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int startingRow = 0,startingCol = 0,endingRow = row-1,endingCol = col-1;

        while(startingRow <= endingRow && startingCol <= endingCol)
        {
            if(startingRow <= endingRow && startingCol <= endingCol)
            {
                for(int i=startingCol;i<=endingCol;i++)
                {
                    ans.push_back(matrix[startingRow][i]);
                }
            }

            startingRow++;

            if(startingRow <= endingRow && startingCol <= endingCol)
            {
                for(int i=startingRow;i<=endingRow;i++)
                {
                    ans.push_back(matrix[i][endingCol]);
                }
            }

            endingCol--;

            if(startingRow <= endingRow && startingCol <= endingCol)
            {
                for(int i=endingCol;i>=startingCol;i--)
                {
                    ans.push_back(matrix[endingRow][i]);
                }
            }

            endingRow--;

            if(startingRow <= endingRow && startingCol <= endingCol)
            {
                for(int i=endingRow;i>=startingRow;i--)
                {
                    ans.push_back(matrix[i][startingCol]);
                }
            }

            startingCol++;
        }
        return ans[k-1];
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends