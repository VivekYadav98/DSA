//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
       map<int,int>m;
       for(auto i:hand)
       {
           m[i]++;
       }
       
       if(N%groupSize != 0)
       {
           return false;
       }
       
       while(m.size() >= groupSize)
       {
           auto it = m.begin();
           int num = it->first;
           m[num]--;
           int cnt = it->second;
           
           if(m[num] == 0)
           {
               m.erase(num);
           }
           
           int k = groupSize-1;
           num++;
           
           while(k>0)
           {
               if(m.find(num) != m.end())
               {
                   m[num]--;
                   if(m[num] == 0)
                   {
                       m.erase(num);
                   }
                   k--;
                   num++;
               }
               else
               {
                   return false;
               }
           }
       }
       return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends