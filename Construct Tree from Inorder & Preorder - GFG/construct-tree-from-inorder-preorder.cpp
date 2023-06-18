//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int ind = 0;
    Node* solve(int in[],int pre[],int s,int e)
    {
        if(s>e)
        {
            return NULL;
        }
        
        int val = pre[ind++];
        Node* root = new Node(val);
        
        for(int i=s;i<=e;i++)
        {
            if(val == in[i])
            {
                root->left = solve(in,pre,s,i-1);
                root->right = solve(in,pre,i+1,e);
            }
        }
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        return solve(in,pre,0,n-1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends