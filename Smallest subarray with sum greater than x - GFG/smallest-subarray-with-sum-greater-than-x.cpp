//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here  
        int ans=INT_MAX;
        int j=0;
        int i=0;
        int sum=0;
        while(i<n){
            sum=sum+arr[i];
            
            if(sum>x){
                while(sum>x && j<=i){
                    sum=sum-arr[j];
                    ans=min(ans,i-j+1);
                    j++;
                }
            }
            i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends