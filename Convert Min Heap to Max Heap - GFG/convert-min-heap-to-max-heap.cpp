//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void maxHeapify(vector<int>& arr,int i,int N)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;
        
        if(left<N && arr[largest] < arr[left])
        {
            largest = left;
        }
        
        if(right<N && arr[largest] < arr[right])
        {
            largest = right;
        }
        
        if(largest != i)
        {
            swap(arr[i],arr[largest]);
            maxHeapify(arr,largest,N);
        }
    }
    
    void buildHeap(vector<int>& arr,int N)
    {
       for(int i=(N-2)/2;i>=0;i--)
       {
           maxHeapify(arr,i,N);
       }
    }
    
    void convertMinToMaxHeap(vector<int> &arr, int N){
       buildHeap(arr,N);
       
       for(int i=N-1;i>=1;i--)
       {
           maxHeapify(arr,0,i);
       }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends