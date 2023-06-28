//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(int digit,int cnt,int n,string output,vector<string>& ans)
	{
	    if(cnt == n-1)
	    {
	        ans.push_back(output);
	        return;
	    }
	    
	    if(digit == 0)
	    {
	        solve(0,cnt+1,n,output+"0",ans);
	        solve(1,cnt+1,n,output+"1",ans);
	    }
	    else
	    {
	        solve(0,cnt+1,n,output+"0",ans);
	    }
	}

    void generateBinaryStrings(int n){
        vector<string>ans;
        string output = "";
        solve(0,0,n,output+"0",ans);
        output = "";
        solve(1,0,n,output+"1",ans);
        
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends