class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string curr = "";
            for(int j=0;j<strs[i].length();j++)
            {
                if(j<temp.length() && strs[i][j] == temp[j])
                {
                    curr += temp[j];
                }
                else
                {
                  j = strs[i].length();  
                }
            }
            temp = curr;
        }
        return temp;
    }
};