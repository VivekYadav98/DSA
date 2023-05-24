//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int n, int m, int k)
    {

        int row = matrix.size();
        int col = matrix[0].size();
        int cnt = 0;
        int startingRow = 0,startingCol = 0,endingRow = row-1,endingCol = col-1;

        while(startingRow <= endingRow && startingCol <= endingCol)
        {
            if(startingRow <= endingRow && startingCol <= endingCol)
            {
                for(int i=startingCol;i<=endingCol;i++)
                {
                   cnt++;
                   if(cnt == k)
                   {
                       return matrix[startingRow][i];
                   }
                }
            }

            startingRow++;

            if(startingRow <= endingRow && startingCol <= endingCol)
            {
                for(int i=startingRow;i<=endingRow;i++)
                {
                    cnt++;
                   if(cnt == k)
                   {
                       return matrix[i][endingCol];
                   }
                }
            }

            endingCol--;

            if(startingRow <= endingRow && startingCol <= endingCol)
            {
                for(int i=endingCol;i>=startingCol;i--)
                {
                    cnt++;
                   if(cnt == k)
                   {
                       return matrix[endingRow][i];
                   }
                }
            }

            endingRow--;

            if(startingRow <= endingRow && startingCol <= endingCol)
            {
                for(int i=endingRow;i>=startingRow;i--)
                {
                    cnt++;
                   if(cnt == k)
                   {
                       return matrix[i][startingCol];
                   }
                }
            }

            startingCol++;
        }
        return 0;
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