class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b)
    {
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int ans = 1;
        int count = 0;
        
        int res = 0;
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[res][1] < pairs[i][0])
            {
                ans++;
                res++;
                pairs[res] = pairs[i];
            }
        }
        return ans;
    }
};