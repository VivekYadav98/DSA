class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            nums.push_back(nums[i]);
        }
        
        vector<int>temp;
        stack<int>s;
        s.push(-1);
        int i = nums.size()-1;
        
        while(!s.empty() && i>=0)
        {
            if(s.top()>nums[i] || (s.size() == 1))
            {
                temp.push_back(s.top());
                s.push(nums[i]);
                i--;
            }
            else
            {
                    s.pop();
            }
        }
        
        reverse(temp.begin(),temp.end());
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(temp[i]);
        }
       
        return ans;
    }
};