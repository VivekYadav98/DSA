class Solution {
public:
     static bool cmp(pair<char,int>a,pair<char,int>b)
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
    
    string frequencySort(string s) {
        map<char,int>m;
        for(auto i:s)
        {
            m[i]++;
        }
        
        vector<pair<char,int>>ans;
        for(auto i:m)
        {
           ans.push_back({(i.first),i.second});
        }
        
        sort(ans.begin(),ans.end(),cmp);
        
        string res = "";
        for(int i=0;i<ans.size();i++)
        {
            while(ans[i].second>0)
            {
                res += ans[i].first;
                ans[i].second--;
            }
        }
        return res;
    }
};