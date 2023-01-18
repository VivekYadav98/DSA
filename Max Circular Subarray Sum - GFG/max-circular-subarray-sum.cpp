//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
       int normalSum = INT_MIN;
       int totalSum = 0;
       int sum = 0;

// Normal Subarray Sum
       for(int i=0;i<num;i++)
       {
           totalSum += arr[i];
           sum += arr[i];
           normalSum = max(normalSum,sum);

           if(sum<0)
           {
               sum =0;
           }
       }

// Total Sum and Normal MInimim Sum
       sum = 0;
       int minimumSum = INT_MAX;
       for(int i=0;i<num;i++)
       {
           sum += arr[i];
           minimumSum = min(minimumSum,sum);

           if(sum>0)
           {
               sum =0;
           } 
       }

// Circular Sum
       int circularSum = totalSum - minimumSum;

       if(circularSum == 0)
       {
           return normalSum;
       }
       
    //   Answer
       int ans = max(normalSum,circularSum);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends