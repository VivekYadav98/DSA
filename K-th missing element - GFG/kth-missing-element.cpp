//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
     vector<int>temp;
        int num = a[0];
        for(int i=0;i<n;i++)
        {
            if(a[i] == num)
            {
                num++;
            }
            else
            {
                temp.push_back(num);
                num++;
                i--;
            }
        }
        
        if(temp.size() < k)
        {
            return -1;
        }
        return temp[k-1];
}