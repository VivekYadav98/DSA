//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool cmp(Job arr1,Job arr2)
    {
        return (arr1.profit > arr2.profit);
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        vector<bool>vis(n+1,false);
        int ans=0,cnt=0;
        
        for(int i=0;i<n;i++)
        {
            int deadline = arr[i].dead;
            int profit = arr[i].profit;
            
            if(vis[deadline] == false)
            {
                ans += profit;
                cnt++;
                vis[deadline] = true;
            }
            else
            {
                int j = deadline-1;
                while(j>=1 && vis[j] == true)
                {
                    j--;
                }
                
                if(j>=1)
                {
                    ans += profit;
                    cnt++;
                    vis[j] = true;
                }
            }
        }
        
        return {cnt,ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends