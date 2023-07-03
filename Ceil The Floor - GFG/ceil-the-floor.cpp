//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
       int ansFloor=INT_MIN,ansCeil=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] <= x)
            {
                ansFloor = max(ansFloor,arr[i]);
            }
            
            if(arr[i] >= x)
            {
                ansCeil = min(ansCeil,arr[i]);
            }
        }
        
        if(ansFloor == INT_MIN && ansCeil == INT_MAX)
        {
            return {-1,-1};
        }
        else if(ansFloor == INT_MIN)
        {
            return {-1,ansCeil};
        }
        else if(ansCeil == INT_MAX)
        {
            return {ansFloor,-1};
        }
        return {ansFloor,ansCeil};
}