//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    map<int,int>m;
	    for(int i=0;i<nums.size();i++)
	    {
	        m[nums[i]] = i;
	    }
	    
	    int x=0;
	    for(auto i:m)
	    {
	        m[i.first] = x++;
	    }
	    int cnt = 0;
	    
	    for(int i=0;i<nums.size();i++)
	    {
	        auto it = m.find(nums[i]);
	        int ind = m[it->first];
	        
	        if(nums[ind] != nums[i])
	        {
	           swap(nums[ind],nums[i]);
	           cnt++;
	           i--;
	        }
	    }
	    
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends