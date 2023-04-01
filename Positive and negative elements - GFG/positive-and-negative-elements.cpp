//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    vector<int> arranged(int a[],int n)
    {
       vector<int>num1,num2; 
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
           if(a[i]>0)
           {
               num1.push_back(a[i]);
           }
           else
           {
               num2.push_back(a[i]);
           }
       }
       
       int i=0,j=0;
       bool flag = false;
       while(i<num1.size() && j<num2.size())
       {
           if(flag == false)
           {
               ans.push_back(num1[i]);
               flag = true;
               i++;
           }
           else
           {
               ans.push_back(num2[j]);
               flag = false;
               j++;
           }
       }
       ans.push_back(num2[j]);
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
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    vector<int> ans;
    Solution obj;
    ans=obj.arranged(a,n);
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    }
}

// } Driver Code Ends