//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}

// } Driver Code Ends


/*You have to complete this function*/

void solve(char str[],string output,vector<string>& ans,int i)
{
    if(i == strlen(str))
    {
        if(output.size() != 0 && output[0] != ' ')
        {
          ans.push_back(output);
        }
        return;
    }
    
    solve(str,output+str[i],ans,i+1);
    output.push_back(' ');
    solve(str,output+str[i],ans,i+1);
    output.pop_back();
}

vector<string>  spaceString(char str[])
{
    vector<string>ans;
    string output = "";
    solve(str,output,ans,0);
    return ans;
}