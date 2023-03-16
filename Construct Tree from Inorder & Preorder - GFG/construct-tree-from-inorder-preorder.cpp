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
     Node* solve(int s,int e,int& ind,int preorder[], int inorder[],int n,vector<bool>& vis)
    {
        if(s>e)
        {
            return NULL;
        }

        int data = preorder[ind++];
        Node* root = new Node(data);
        int mid = 0;
        for(int i=0;i<n;i++)
        {
            if(data == inorder[i] && !vis[i])
            {
                vis[i] = true;
                mid = i;
                break;
            }
        }

        root->left = solve(s,mid-1,ind,preorder,inorder,n,vis);
        root->right = solve(mid+1,e,ind,preorder,inorder,n,vis);
        return root;
    }
        
    Node* buildTree(int in[],int pre[], int n)
    {
        int s=0,e=n-1;
        int ind = 0;
        vector<bool>vis(n,false);
        return solve(s,e,ind,pre,in,n,vis);
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