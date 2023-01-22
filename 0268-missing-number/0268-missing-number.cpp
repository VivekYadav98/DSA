class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            sum1 += nums[i];
            sum2 += i+1;
        }
        return sum2-sum1;
    }
};