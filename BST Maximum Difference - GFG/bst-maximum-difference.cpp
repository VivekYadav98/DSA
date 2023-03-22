//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    Node* res = NULL;
    void rootToTarget(Node* root,int target,int& sum)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->data == target)
        {
            res = root;
            return;
        }
        
        sum += root->data;
        if(target < root->data)
        {
           rootToTarget(root->left,target,sum); 
        }
        else
        {
            rootToTarget(root->right,target,sum);
        }
    }
    
    void targetToLeaf(Node* root,int& temp,int sum,int& ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        temp += root->data;
        if(root->left == NULL && root->right == NULL)
        {
            ans = max(ans , sum-temp);
        }
        
        targetToLeaf(root->left,temp,sum,ans);
        targetToLeaf(root->right,temp,sum,ans);
        temp -= root->data;
    }
    
    int maxDifferenceBST(Node *root,int target){
        int sum = 0;
        rootToTarget(root,target,sum);
        
        if(res == NULL)
        {
            return -1;
        }
        
        int sumLeft = 0;
        int sumRight = 0;
        int ans = INT_MIN;
        targetToLeaf(res->left,sumLeft,sum,ans);
        targetToLeaf(res->right,sumRight,sum,ans);
        
        if(ans == INT_MIN)
        {
            return sum;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends