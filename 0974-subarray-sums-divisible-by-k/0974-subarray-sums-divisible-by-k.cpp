class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int>m;
        int sum=0,remainder=0;
        m[remainder]++;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            remainder = sum%k;
            
            if(remainder<0)
            {
                remainder += k;
            }
            
            if(m.find(remainder) != m.end())
            {
                ans += m[remainder];
            }
             m[remainder]++;
        }
        return ans;
    }
};