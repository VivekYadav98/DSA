//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        vector<int>leftSmallest;
        reverse(arr.begin(),arr.end());
        
        int n = arr.size();
        int i = n-1;
        stack<pair<int,int>>s;
        while(i>=0)
        {
            if(s.empty())
            {
                leftSmallest.push_back(-1);
                s.push({arr[i],n-1-i});
                i--;
            }
            else
            {
                if(s.top().first < arr[i])
                {
                    leftSmallest.push_back(s.top().second);
                    s.push({arr[i],n-1-i});
                    i--;
                }
                else
                {
                    s.pop();
                }
            }
        }
        
        while(!s.empty())
        {
            s.pop();
        }
        
        vector<int>rightSmallest;
        reverse(arr.begin(),arr.end());
        
        i = n-1;
        while(i>=0)
        {
            if(s.empty())
            {
                rightSmallest.push_back(-1);
                s.push({arr[i],i});
                i--;
            }
            else
            {
                if(s.top().first < arr[i])
                {
                    rightSmallest.push_back(s.top().second);
                    s.push({arr[i],i});
                    i--;
                }
                else
                {
                    s.pop();
                }
            }
        }
        
        reverse(rightSmallest.begin(),rightSmallest.end());
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(leftSmallest[i] == -1 && rightSmallest[i] == -1)
            {
                ans.push_back(-1);
            }
            else if(leftSmallest[i] == -1 && rightSmallest[i] != -1)
            {
                ans.push_back(rightSmallest[i]);
            }
            else if(leftSmallest[i] != -1 && rightSmallest[i] == -1)
            {
                ans.push_back(leftSmallest[i]);
            }
            else
            {
                int ind1 = abs(leftSmallest[i]-i);
                int ind2 = abs(rightSmallest[i]-i);
                
                if(ind1 == ind2 && arr[leftSmallest[i]] != arr[rightSmallest[i]])
                {
                    if(arr[leftSmallest[i]] < arr[rightSmallest[i]])
                    {
                        ans.push_back(leftSmallest[i]);
                    }
                    else
                    {
                        ans.push_back(rightSmallest[i]);
                    }
                }
                else if(arr[leftSmallest[i]] == arr[rightSmallest[i]])
                {
                    if(ind1 < ind2)
                    {
                       ans.push_back(leftSmallest[i]); 
                    }
                    else if(ind1 > ind2)
                    {
                        ans.push_back(rightSmallest[i]);
                    }
                    else
                    {
                        ans.push_back(min(leftSmallest[i],rightSmallest[i]));
                    }
                }
                else
                {
                    if(ind1<ind2)
                    {
                        ans.push_back(leftSmallest[i]);
                    }
                    else
                    {
                        ans.push_back(rightSmallest[i]);
                    }
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
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends