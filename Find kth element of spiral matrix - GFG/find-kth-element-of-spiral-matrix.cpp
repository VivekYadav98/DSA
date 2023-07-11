//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int startingRow=0,startingCol=0,endingRow=n-1,endingCol=m-1,count=0;
 		
 		while(startingRow<=endingRow && startingCol<=endingCol)
 		{
 		    for(int i=startingCol;i<=endingCol && count<k;i++)
 		    {
 		        count++;
 		        
 		        if(count == k)
 		        {
 		            return a[startingRow][i];
 		        }
 		    }
 		    
 		    startingRow++;
 		    for(int i=startingRow;i<=endingRow && count<k;i++)
 		    {
 		        count++;
 		        
 		        if(count == k)
 		        {
 		            return a[i][endingCol];
 		        }
 		    }
 		    
 		    endingCol--;
 		    for(int i=endingCol;i>=startingCol && count<k;i--)
 		    {
 		        count++;
 		        
 		        if(count == k)
 		        {
 		            return a[endingRow][i];
 		        }
 		    }
 		    
 		    endingRow--;
 		    for(int i=endingRow;i>=startingRow && count<k;i--)
 		    {
 		        count++;
 		        
 		        if(count == k)
 		        {
 		            return a[i][startingCol];
 		        }
 		    }
 		    
 		    startingCol++;
 		}
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
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends