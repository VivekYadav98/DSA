//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPallindrome(long long int N){
        vector<int>ans;
        while(N>0)
        {
            long long int num = N&1;
            ans.push_back(num);
            N = N>>1;
        }
        
        reverse(ans.begin(),ans.end());
        int i=0,j=ans.size()-1;
        
        while(i<j)
        {
            if(ans[i] != ans[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.isPallindrome(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends