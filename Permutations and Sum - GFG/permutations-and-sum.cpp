//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	void solve(string& s,set<string>& res,int i)
	{
	    if(i>=s.length())
	    {
	        res.insert(s);
	        return;
	    }
	    
	    for(int ind=i;ind<s.length();ind++)
	    {
	        swap(s[i],s[ind]);
	        solve(s,res,i+1);
	        swap(s[ind],s[i]);
	    }
	}
	vector<int> permutaion(int N) {
	    set<string>res;
	    string s = to_string(N);
	    solve(s,res,0);
	    int sum=0;
	    int cnt = res.size();
	    for(auto i:res)
	    {
	        int num = stoi(i);
	        sum += num;
	    }
	    return {cnt,sum};
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.permutaion(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends