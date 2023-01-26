//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
   void solve(vector<int>& candidates,int target,vector<int>& temp,vector<vector<int>>& ans,int i)
    {
       if(i == candidates.size())
       {
           if(target == 0)
           {
               ans.push_back(temp);
           }
           return;
       }
       
       if(candidates[i] <= target)
       {
           temp.push_back(candidates[i]);
           solve(candidates,target-candidates[i],temp,ans,i);
           temp.pop_back();
       }

       solve(candidates,target,temp,ans,i+1);
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(A,B,temp,ans,0);
        
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