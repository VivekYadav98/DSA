//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivot = arr[low];
       int cnt=0;
       for(int i=low;i<=high;i++)
       {
           if(i != low && pivot >= arr[i])
           {
               cnt++;
           }
       }
       
       int pivotIndex = low+cnt;
       swap(arr[pivotIndex],arr[low]);
       
       int i=low,j=high;
       
       while(i<j && i<=high && j>=low)
       {
           while(i<=high && arr[i] <= arr[pivotIndex])
           {
               i++;
           }
           
           while(j>=low && arr[j] > arr[pivotIndex])
           {
               j--;
           }
           
           if(i<j && i<=high && j>=low)
           {
               swap(arr[i],arr[j]);
               i++;
               j--;
           }
       }
       
       return pivotIndex;
    }
    
    void quickSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int p = partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends