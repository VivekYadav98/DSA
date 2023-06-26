//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key,int val)
        {
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int,node*>m;
    int size;
    
    LRUCache(int cap)
    {
        size = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode)
    {
        node* prevnode = delnode->prev;
        node* nextnode = delnode->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    
    int GET(int key)
    {
        if(m.find(key) != m.end())
        {
            node* resnode = m[key];
            int res = resnode->val;
            deletenode(resnode);
            m.erase(key);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(m.find(key) != m.end())
        {
            node* existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        
        if(m.size() == size)
        {
            node* delnode = tail->prev;
            m.erase(delnode->key);
            deletenode(delnode);
        }
        
        addnode(new node(key,value));
        m[key] = head->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends