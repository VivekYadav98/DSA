class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b)
    {
       return (a.second>b.second);
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
         map<int,int>m;
        for(auto i:nums)
        {
            m[i]++;
        }
        
        vector<pair<int,int>>ans;
        for(auto i:m)
        {
           ans.push_back({i.first,i.second});
        }
        
        sort(ans.begin(),ans.end(),cmp);
        
        while(ans.size()>k)
        {
            ans.pop_back();
        }
        
        vector<int>res;
        for(auto i:ans)
        {
            res.push_back(i.first);
        }
        return res;
    }
};