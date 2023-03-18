//{ Driver Code Starts
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node* solve(int mini,int maxi,int post[],int size,int& ind)
{
    if(ind<0)
    {
        return NULL;
    }
    
    if(post[ind] < mini || post[ind] > maxi)
    {
        return NULL;
    }
    
    Node* root = new Node(post[ind--]);
    root->right = solve(root->data,maxi,post,size,ind);
    root->left = solve(mini,root->data,post,size,ind);
    return root;
}
Node *constructTree (int post[], int size)
{
   int mini = INT_MIN;
   int maxi = INT_MAX;
   int ind = size-1;
   return solve(mini,maxi,post,size,ind);
}