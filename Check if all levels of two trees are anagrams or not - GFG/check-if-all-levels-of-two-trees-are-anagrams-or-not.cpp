//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
//User function Template for C++

class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        queue<Node*>q1;
        q1.push(root1);
        queue<Node*>q2;
        q2.push(root2);
        
        
        while(!q1.empty() && !q2.empty())
        {
            unordered_map<int,int>m1;
            unordered_map<int,int>m2;
            int count1 = q1.size();
            int count2 = q2.size();
            
            for(int i=0;i<count1;i++)
            {
                Node* temp = q1.front();
                q1.pop();
                m1[temp->data]++;
                
                if(temp->left)
                {
                    q1.push(temp->left);
                }
                if(temp->right)
                {
                    q1.push(temp->right);
                }
            }
            
            for(int i=0;i<count2;i++)
            {
                Node* temp = q2.front();
                q2.pop();
                
                m2[temp->data]++;
                
                if(temp->left)
                {
                    q2.push(temp->left);
                }
                if(temp->right)
                {
                    q2.push(temp->right);
                }
            }
            
            for(auto i:m1)
            {
                if(m2.find(i.first) == m2.end())
                {
                    return false;
                }
                else if(m1[i.first] != m2[i.first])
                {
                    return false;
                }
            }
            
            for(auto i:m2)
            {
                if(m1.find(i.first) == m1.end())
                {
                    return false;
                }
                else if(m1[i.first] != m2[i.first])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends