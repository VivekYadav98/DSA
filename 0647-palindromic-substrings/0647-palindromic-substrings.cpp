class Solution {
public:
    int countSubstrings(string s) {
        string S = s;
         int n = S.length();
        int start = 0,end=1;
        int count = 0;
        
        for(int i=1;i<n;i++)
        {
            // EVEN LENGTH
            int low = i-1;
            int high = i;
            
            while(low>=0 && high<n && S[low] == S[high])
            {
                count++;
                low--;
                high++;
            }
            
        //   ODD LENGTH
            low = i-1;
            high = i+1;
            
            while(low>=0 && high<n && S[low] == S[high])
            {
               count++;
                low--;
                high++;
            }
        }
        
        return s.length()+count;
    }
};