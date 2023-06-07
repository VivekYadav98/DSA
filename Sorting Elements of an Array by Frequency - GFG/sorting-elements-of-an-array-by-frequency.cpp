//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first == b.first)
        {
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    
    vector<int> sortByFreq(int arr[],int n)
    {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }

        vector<pair<int,int>>temp;
        for(auto it:m)
        {
            temp.push_back({it.second,it.first});
        }
        
        sort(temp.begin(),temp.end(),cmp);
        int i=0;
        while(i<temp.size())
        {
            int cnt = temp[i].first;
            int val = temp[i].second;

            while(cnt)
            {
                ans.push_back(val);
                cnt--;
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends