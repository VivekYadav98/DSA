//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int>A, int X) {
        int N = A.size();
        sort(A.begin(),A.end());
        int ans=INT_MAX,sum=0;
        for(int k=0;k<N;k++)
        {
            int i=k+1,j=N-1;
            while(i<j)
            {
                sum = A[i]+A[j]+A[k];
                
                if(sum>X)
                {
                    j--;
                }
                else if(sum<X)
                {
                    i++;
                }
                else
                {
                    return sum;
                }
                
                if(abs(X-sum) < abs(X-ans))
                {
                    ans = sum;
                }
                else if(abs(X-sum) == abs(X-ans))
                {
                    ans = max(ans,sum);
                }
            }
        }
        
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.

// } Driver Code Ends