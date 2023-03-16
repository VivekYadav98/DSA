//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
 Node* solve(int s,int e,int& ind,int postorder[],int inorder[],int n)
    {
        if(s>e)
        {
            return NULL;
        }

        int data = postorder[ind--];
        Node* root = new Node(data);
        int mid = 0;
        for(int i=0;i<n;i++)
        {
            if(data == inorder[i])
            {
                mid = i;
                break;
            }
        }

        root->right = solve(mid+1,e,ind,postorder,inorder,n);
        root->left = solve(s,mid-1,ind,postorder,inorder,n);
        return root;
    }
    
Node *buildTree(int in[], int post[], int n) {
     int s=0,e=n-1;
        int ind = e;
        return solve(s,e,ind,post,in,n);
}
