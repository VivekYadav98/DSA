//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
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
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int findK(int matrix[MAX][MAX], int n, int m, int k)
{
        int row = n;
        int col = m;
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

