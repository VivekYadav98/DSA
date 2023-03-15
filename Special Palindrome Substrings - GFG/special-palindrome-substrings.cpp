//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string s1, string s2){
        int ans = INT_MAX;
        for(int i=0;i<=s1.length()-s2.length();i++)
        {
            int cnt = 0;
            string temp = s1;
            int k=i;
            for(int j=0;j<s2.length();j++)
            {
                if(temp[k] != s2[j])
                {
                    cnt++;
                }
                temp[k] = s2[j];
                k++;
            }
            
            int s=0,e=temp.length()-1;
            string temp1 = temp;
            while(s<e)
            {
                if(temp[s] != temp[e])
                {
                    temp[e] = temp[s];
                    temp1[s] = temp1[e];
                    cnt++;
                }
                s++;
                e--;
            }
            
            if(((temp.find(s2) != string::npos) || (temp1.find(s2) != string::npos)) && cnt<ans)
            {
                ans = min(ans,cnt);
            }
        }
        
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends