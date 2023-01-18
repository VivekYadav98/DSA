#include<bits/stdc++.h>
class Solution {
public:

    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
     vector<vector<int>> mappings(26);  // stores array of indices for each character in s
        for(int i = 0; i < size(s); i++)
        {
            mappings[s[i] - 'a'].push_back(i);
        }
        
        for(auto& word : words) 
        {
            int  found = 1;
            // i = index in word | prev = index in s matched for word[i-1]
            for(int i = 0, prev = -1; found == 1 && i < word.size(); i++) 
            {
                auto& v = mappings[word[i]-'a'];
                auto it = upper_bound(v.begin(), v.end(), prev);  
                // check if current character exists in s with index > prev
                if(it == v.end())
                {
                    found = false;
                }// doesn't exist
                else
                {
                    prev = *it;   
                }// update prev for next check
            }
            ans += found;
        }
        return ans;
    }
};