//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>ans;
        reverse(arr.begin(),arr.end());
        int i = 1;
        ans.push_back(-1);
        stack<long long>s;
        s.push(arr[0]);
        
        while(i<n)
        {
            if(!s.empty() && arr[i]>=s.top())
            {
                 s.pop();
            }
            else 
            {
                if(!s.empty())
                {
                  ans.push_back(s.top());
                }
                else
                {
                    ans.push_back(-1);
                }
                s.push(arr[i]);
                i++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends