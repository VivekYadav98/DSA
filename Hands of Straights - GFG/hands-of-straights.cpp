//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
          priority_queue<pair<int,int>>pq;
        queue<pair<int,int>>q;

        unordered_map<int,int>m;
        for(auto i:hand)
        {
            m[i]++;
        }

        for(auto i:m)
        {
            pq.push({i.first,i.second});
        }

        while(!pq.empty())
        {
            int k = groupSize;

            while(k>0)
            {
                k--;

                int num1 = pq.top().first;
                int cnt = pq.top().second;
                pq.pop();

                int num2 = INT_MIN;

                if(k>0 && pq.empty())
                {
                    return false;
                }
                else if(!pq.empty())
                {
                    num2 = pq.top().first;
                }
                
                if(cnt-1 > 0)
                {
                    q.push({num1,cnt-1});
                }

                if(k>0 && num2+1 != num1)
                {
                    return false;
                }
            }

            while(!q.empty())
            {
                pq.push({q.front().first,q.front().second});
                q.pop();
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