class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         string ans = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string temp = "";
            string s = strs[i];
            
            for(int j=0;j<s.length() && j<ans.length();j++)
            {
                if(s[j] == ans[j])
                {
                    temp += s[j];
                }
                else
                {
                    break;
                }
            }
            
            if(temp.size()<ans.size())
            {
                ans = temp;
            }
        }
        if(ans.size() == 0)
        {
            return "";
        }
        return ans;
    }
};