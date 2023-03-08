//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        map<char,int>m1;
        map<char,int>m2;
        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;
        }
        
        vector<Node*>ans;
        int k = s.length();
        Node* curr = head;
        Node* prev = head;
        Node* prev1 = head;
        Node* temp = curr;
        int cnt = 0;
        
        while(curr != NULL)
        {
            if(cnt < k)
            {
              m2[curr->data]++;
              cnt++;
              temp = curr;
              curr = curr->next;
            }
            else if(cnt == k)
            {
                if(m1 == m2)
                {
                    temp->next = NULL;
                    
                    // if(prev1 != head)
                    // {
                    //     prev1->next = NULL;
                    // }
                    
                    ans.push_back(prev);
                    cnt = 0;
                    m2.clear();
                    prev1 = prev;
                    prev = curr;
                }
                else
                {
                    m2[prev->data]--;
                    if(m2[prev->data] == 0)
                    {
                        m2.erase(prev->data);
                    }
                    cnt--;
                    prev1 = prev;
                    prev = prev->next;
                }
            }
        }
        
        if(m1 == m2)
        {
            // if(prev1 != head)
            // {
            //     prev1->next = NULL;
            // }
            ans.push_back(prev);
            cnt = 0;
            m2.clear();
            prev = curr;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends