class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        stack<int>s;
        s.push(-1);
        int i = nums2.size()-1;
        
        while(!s.empty() && i>=0)
        {
            if(s.top()>nums2[i])
            {
                temp.push_back(s.top());
                s.push(nums2[i]);
                i--;
            }
            else if(s.top()<nums2[i])
            {
                if(s.size() == 1)
                {
                    temp.push_back(-1);
                    s.push(nums2[i]);
                    i--;
                }
                else 
                {
                    s.pop();
                }
            }
        }
        reverse(temp.begin(),temp.end());
        unordered_map<int,int>m;
        for(int i=0;i<nums2.size();i++)
        {
            m[nums2[i]] = temp[i];
        }
        
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};