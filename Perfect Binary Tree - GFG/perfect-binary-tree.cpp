//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    bool isPerfect(Node *root)
    {
        queue<Node*>q;
        q.push(root);
        bool flag = true;
        
        while(!q.empty())
        {
            bool check = false;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node* temp = q.front();
                q.pop();
                
                if(temp->left && flag == true)
                {
                    check = true;
                    q.push(temp->left);
                }
                else if(temp->left && flag == false)
                {
                    return false;
                }
                else
                {
                    if(check == true)
                    {
                        return false;
                    }
                    flag = false;
                }
                
                if(temp->right && flag == true)
                {
                    check = true;
                    q.push(temp->right);
                }
                else if(temp->right && flag == false)
                {
                    return false;
                }
                else
                {
                    if(check == true)
                    {
                        return false;
                    }
                    flag = false;
                }
                
                if((temp->left != NULL && temp->right == NULL) || 
                  (temp->left != NULL && temp->right == NULL))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {

        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        bool res = obj.isPerfect(root);
        if (res)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
// } Driver Code Ends