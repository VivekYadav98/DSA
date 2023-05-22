//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long>ans(n,0);
        vector<long long>temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        
        vector<long long>preSum(n,0);
        for(int i=1;i<n;i++)
        {
            preSum[i] += preSum[i-1] + temp[i-1]; 
        }
        
        for(int i=0;i<n;i++)
        {
            long long val = arr[i];
            
            int s = 0,e=n-1;
            int ind = 0;
            while(s <= e)
            {
                int mid = (s+e)/2;
                
                if(temp[mid] == val)
                {
                    ind = mid;
                    break;
                }
                else if(temp[mid] < val)
                {
                    s = mid+1;
                }
                else
                {
                    e = mid-1;
                }
            }
            
            while(ind>0 && temp[ind] == temp[ind-1])
            {
                ind--;
            }
            
            long long sum = preSum[ind];
            ans[i] = sum;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends