class Solution {
public:
    bool isValid(string s)
    {
        if(s[0] == '0' || stoi(s)>255)
        {
            return false;
        }
        return true;
    }
    
    void solve(string s,int index,vector<string>& ans,string output,int count)
    {
        if(index >= s.length() || count == 4)
        {
            if(index>=s.length() && count == 4)
            {
                ans.push_back(output.substr(0,output.length()-1));
            }
            return;
        }
        
        solve(s,index+1,ans,output+s[index]+".",count+1);
        
        if(index+2 <= s.length() && isValid(s.substr(index,2)))
        {
           solve(s,index+2,ans,output+s.substr(index,2)+".",count+1);
        }
        
        if(index+3 <= s.length() && isValid(s.substr(index,3)))
           {
               solve(s,index+3,ans,output+s.substr(index,3)+".",count+1);
           }
           
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string output = "";
        solve(s,0,ans,output,0);
        return ans;
    }
};