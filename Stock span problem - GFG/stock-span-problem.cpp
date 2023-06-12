//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>>st;
       vector<int>ans(n,0);
       int i=0;
       while(i<n)
       {
           if(st.empty())
           {
               st.push({price[i],i});
               ans[i] = 1;
               i++;
           }
           else 
           {
               if(st.top().first > price[i])
               {
                   st.push({price[i],i});
                   ans[i] = 1;
                   i++;
               }
               else
               {
                   int cnt = 1;
                   while(!st.empty() && st.top().first <= price[i])
                   {
                       cnt += ans[st.top().second];
                       st.pop();
                   }
                   
                   ans[i] = cnt;
                   st.push({price[i],i});
                   i++;
               }
           }
       }
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends