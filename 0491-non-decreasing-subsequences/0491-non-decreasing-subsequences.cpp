class Solution {
public:
    void solve(int index,vector<int>& nums,vector<int> output,set<vector<int>>& s)
    {
        if(index>=nums.size())
        {
            if(output.size() >= 2)
            {
              s.insert(output);
            }
            return;
        }
        
        solve(index+1,nums,output,s);
        
        
        if(output.empty()==true || nums[index] >= output.back())
        {
            output.push_back(nums[index]);
        }
        
        solve(index+1,nums,output,s);
        // output.pop_back();
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        set<vector<int>>s;
        solve(0,nums,output,s);
        
        for(auto i:s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};