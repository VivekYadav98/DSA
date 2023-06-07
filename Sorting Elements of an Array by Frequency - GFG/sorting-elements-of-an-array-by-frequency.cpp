#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 bool cmp(pair<int,int>& a,pair<int,int>& b)
{
    if(a.first == b.first)
    {
        return a.second<b.second;
    }
    return a.first>b.first;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> arr[i];
	    }
	    
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
        
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;
	}
	
	return 0;
}