//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    static bool mycomp(long long int a,long long int b ){
        
        return abs(a)<abs(b);
    }
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        int i=0;
        long long int sum=0;
        bool flag=false;
        int j=INT_MAX;
        
        while(i<n){
            if(a[i]<0){
                if(k>0){
                   sum=sum+(-1)*a[i];
                   k--;
                }
                else {
                    sum=sum+a[i];
                }
            }
            else {
                sum=sum+a[i];
            }
            i++;
        }
        sort(a,a+n,mycomp);
        
        if(k==0){
            return sum;
        }
        else{
            if(flag==true || k%2==0){
                return sum;
            }
            else {
               if(a[0]<0){
                   return sum+2*a[0];
               }
               else {
                   return sum-2*a[0];
               }
            }
        }
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends