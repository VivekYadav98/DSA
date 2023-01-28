//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<N;i++)
        {
            pq.push({A[i]+B[N-1],{i,N-1}});
        }
        
        vector<int>ans;
        
        while(!pq.empty() && K--)
        {
            int data = pq.top().first;
            ans.push_back(data);
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if(y != 0)
            {
                pq.push({A[x]+B[y-1],{x,y-1}});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends