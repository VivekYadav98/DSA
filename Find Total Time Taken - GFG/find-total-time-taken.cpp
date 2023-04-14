//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        long long int ans = 0;
        unordered_map<int,int>m;
        int currTime = 0;
        m[arr[0]] = 0;
        
        
        for(int i=1;i<n;i++)
        {
            if(m.find(arr[i]) == m.end())
            {
                ans++;
                currTime++;
                m[arr[i]] = currTime;
            }
            else
            {
                int ind = arr[i] - 1;
                int prev = m[arr[i]];
                currTime++;
                int newTime = currTime;
                
                if(newTime-prev >= time[ind])
                {
                    ans++;
                }
                else
                {
                    ans += time[ind]-(newTime-prev)+1;
                    currTime += time[ind]-(newTime-prev);
                }
                
                m.erase(arr[i]);
                m[arr[i]] = currTime;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        
        vector<int> time(n);
        Array::input(time,n);
        
        Solution obj;
        int res = obj.totalTime(n, arr, time);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends