//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  static bool cmp(pair<int,int>a,pair<int,int>b)
  {
      if(a.second == b.second)
      {
          return a.first < b.first;
      }
      else
      {
          return a.second > b.second;
      }
  }
  
    vector<int> kTop(int a[], int n, int k) 
    { 
        vector<pair<int,int>>vec;
        vector<int>ans;
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++)
        {
            m[a[i]]++;
            
            if(m[a[i]] > 1)
            {
                for(int j=0;j<vec.size();j++)
                {
                    if(vec[j].first == a[i])
                    {
                        vec[j].second = m[a[i]];
                        break;
                    }
                }
            }
            else
            {
                vec.push_back({a[i],m[a[i]]});
            }
            
            sort(vec.begin(),vec.end(),cmp);
            int count = 0;
            int j=0;
            
            while(count<k && j<vec.size())
            {
                ans.push_back(vec[j].first);
                j++;
                count++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}

// } Driver Code Ends