//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void solve(int i,vector<int>&A,int target,vector<int>&output,vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(output);
            return;
        }
        
        
        for(int j=i;j<A.size();j++)
        {
            if(j>i && A[j] == A[j-1])
            {
                continue;
            }
            
            if(target < A[j])
            {
                break;
            }
            
            output.push_back(A[j]);
            solve(j,A,target-A[j],output,ans);
            output.pop_back();
        }
    }
  
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        vector<vector<int>>ans;
        vector<int>output;
        solve(0,A,B,output,ans);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends