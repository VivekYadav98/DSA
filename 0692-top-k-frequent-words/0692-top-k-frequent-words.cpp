class Solution {
public:
    static bool cmp(pair<string,int>a,pair<string,int>b)
    {
        if(a.second == b.second)
        {
            return a.first<b.first;
        }
        else
        {
            return (a.second>b.second);
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        for(auto i:words)
        {
            m[i]++;
        }
        
        vector<pair<string,int>>ans;
        for(auto i:m)
        {
           ans.push_back({(i.first),i.second});
        }
        
        sort(ans.begin(),ans.end(),cmp);
        
        while(ans.size()>k)
        {
            ans.pop_back();
        }
        vector<string>res;
        for(auto i:ans)
        {
            res.push_back(i.first);
        }
        return res;
    }
};