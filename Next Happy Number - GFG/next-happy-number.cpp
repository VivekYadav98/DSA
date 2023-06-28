//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int nextHappy(int N){
        N = N+1;
        int num = N;
        while(true)
        {
            int sum = 0;
            while(num>0)
            {
                int digit = num%10;
                sum += digit*digit;
                num = num/10;
            }
            
            if(sum == 1 || sum == 7)
            {
                return N;
            }
            else if(sum>0 && sum<10)
            {
                N++;
                num = N;
            }
            else
            {
                num = sum;
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends