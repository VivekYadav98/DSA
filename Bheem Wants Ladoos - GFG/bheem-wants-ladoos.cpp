//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    void mapping(Node* root,unordered_map<Node*,vector<Node*>>& m,int val,Node* &target)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->data == val)
        {
            target = root;
        }
        
        if(root->left)
        {
            m[root].push_back(root->left);
            m[root->left].push_back(root);
            mapping(root->left,m,val,target);
        }
        if(root->right)
        {
            m[root].push_back(root->right);
            m[root->right].push_back(root);
            mapping(root->right,m,val,target);
        }
    }
    
    int ladoos(Node* root, int home, int k)
    {
        int ans = 0;
        unordered_map<Node*,vector<Node*>>m;
        Node* target = NULL;
        mapping(root,m,home,target);
        
        if(target == NULL)
        {
            return home;
        }
        ans += home;
        unordered_map<Node*,bool>vis;
        
        queue<Node*>q;
        q.push(target);
        
        while(!q.empty() && k>0)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node* node = q.front();
                q.pop();
                
                vis[node] = true;
                
                for(auto it:m[node])
                {
                    if(vis.find(it) == vis.end())
                    {
                      ans += it->data;
                      q.push(it);
                    }
                }
            }
            k--;
        }
        return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends