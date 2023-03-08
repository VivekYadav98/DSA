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
    bool check(int count1[],int count2[])
    {
        for(int i=0;i<26;i++)
        {
            if(count1[i] != count2[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<Node*> findAnagrams(struct Node* head, string s) {
       int count1[26] = {0};
       int count2[26] = {0};
        for(int i=0;i<s.length();i++)
        {
            count1[s[i]-'a']++;
        }
        
        vector<Node*>ans;
        int k = s.length();
        Node* curr = head;
        Node* prev = head;
        Node* temp = curr;
        int cnt = 0;
        
        while(curr != NULL)
        {
            if(cnt < k)
            {
              count2[curr->data - 'a']++;
              cnt++;
              temp = curr;
              curr = curr->next;
            }
            else if(cnt == k)
            {
                if(check(count1,count2))
                {
                    temp->next = NULL;
                   
                    ans.push_back(prev);
                    cnt = 0;
                    
                    for(int i=0;i<26;i++)
                    {
                        count2[i] = 0;
                    }
                    prev = curr;
                }
                else
                {
                    count2[prev->data - 'a']--;
                    cnt--;
                    prev = prev->next;
                }
            }
        }
        
       if(check(count1,count2))
        {
            ans.push_back(prev);
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