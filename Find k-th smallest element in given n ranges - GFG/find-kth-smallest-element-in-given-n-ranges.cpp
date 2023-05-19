//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        vector<int>ans;
        sort(range.begin(),range.end());
        int res = 0;
        for(int i=1;i<range.size();i++)
        {
            if(range[i][0] <= range[res][1])
            {
                range[res][0] = min(range[res][0],range[i][0]);
                range[res][1] = max(range[res][1],range[i][1]);
            }
            else
            {
                res++;
                range[res] = range[i];
            }
        }
        
        vector<vector<int>>arr;
        for(int i=0;i<=res;i++)
        {
            arr.push_back(range[i]);
        }
        
        
        for(int i=0;i<queries.size();i++)
        {
            int k = queries[i];
            int size = 0;
            int cnt = 0;
            bool flag = false;
            
            for(int j=0;j<arr.size();j++)
            {
                k -= size;
                size += arr[j][1]-arr[j][0]+1;
                cnt = arr[j][1]-arr[j][0]+1;
                
                if(k <= cnt)
                {
                    flag = true;
                    int num = arr[j][0] +k-1;
                    ans.push_back(num);
                    break;
                }
            }
            
            if(flag == false)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends