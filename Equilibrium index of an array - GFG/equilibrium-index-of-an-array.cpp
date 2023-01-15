//{ Driver Code Starts
#include <iostream>
using namespace std;
#include <stdio.h>
 
int findEquilibrium(int [], int );
 
int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<findEquilibrium (a,n)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends


/* You are required to complete this method*/
int findEquilibrium(int A[], int n)
{
        int sumLeft[n] = {0};
        int sumRight[n] = {0};
        sumLeft[0] = 0;
        sumRight[n-1] = 0; 
        
        for(int i=1;i<n;i++)
        {
            sumLeft[i] = sumLeft[i-1] + A[i-1];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            sumRight[i] = sumRight[i+1] + A[i+1];
        }
        
        for(int i=0;i<n;i++)
        {
            if(sumLeft[i] == sumRight[i])
            {
                return i;
            }
        }
        return -1;
}