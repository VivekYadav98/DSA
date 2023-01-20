class Solution {
public:
//     int solve(vector<int>& nums,int index,int prevInd)
//     {
//         if(index == nums.size())
//         {
//             return 0;
//         }
        
//        int ans = 0 + solve(nums,index+1,prevInd);
        
//         if(prevInd == -1 || nums[index]>nums[prevInd])
//         {
//             ans = max(ans,1+solve(nums,index+1,index));
//         }
//         return ans;
//     }
    
     int solveMem(vector<int>& nums,int index,int prevInd,vector<vector<int>>& dp)
    {
        if(index == nums.size())
        {
            return 0;
        }
        
         if(dp[index][prevInd+1] != -1)
         {
             return dp[index][prevInd+1];
         }
         
       int ans = 0 + solveMem(nums,index+1,prevInd,dp);
        
        if(prevInd == -1 || nums[index]>nums[prevInd])
        {
            ans = max(ans,1+solveMem(nums,index+1,index,dp));
        }
        return dp[index][prevInd+1] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solveMem(nums,0,-1,dp);
    }
};