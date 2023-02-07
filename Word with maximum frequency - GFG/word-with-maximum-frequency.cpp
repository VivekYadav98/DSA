//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;



string maximumFrequency(string s);

int main()
{
    int t;cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++)
    {

        string s;
        getline(cin,s);
        
        
        cout << maximumFrequency(s) << endl;

    }
    return 0;
}

// } Driver Code Ends

#include<bits/stdc++.h>
string maximumFrequency(string s){
        unordered_map<string,int>m;
        unordered_map<string,int>m1;
        string temp = "";
        string ans = "";
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' ')
            {
                m[temp]++;
                
                if(m1.find(temp) == m1.end())
                {
                  m1[temp] = i;
                }
                temp = "";
            }
            else
            {
              temp += s[i];
            }
        }
        
        m[temp]++;
        
        if(m1.find(temp) == m1.end())
        {
          m1[temp] = s.length()-1;
        }
        
        int maxi = 0;
        string st = "";
        for(auto i:m)
        {
            if(i.second > maxi)
            {
                ans = i.first + " " + to_string(i.second);
                maxi = i.second;
                st = i.first;
            }
            else if(i.second == maxi && m1[i.first] < m1[st])
            {
                ans = i.first + " " + to_string(i.second);
                maxi = i.second;
                st = i.first;
            }
        }
        return ans;
}

