//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        int l1=0,l2=0;
        Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1 != NULL)
        {
            l1++;
            temp1 = temp1->next;
        }
        
        while(temp2 != NULL)
        {
            l2++;
            temp2 = temp2->next;
        }
        
        int len = 0;
        if(l1>l2)
        {
            len = l1-l2;
            int count=0;
            while(head1 != NULL && count != len)
            {
                count++;
                head1 = head1->next;
            }
            
            while(head1 != NULL && head2 != NULL && head1 != head2)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            
            if(head1 != NULL && head2 != NULL)
            {
                return head2->data;
            }
        }
        else
        {
            len = l2-l1;
            int count=0;
            while(head2 != NULL && count != len)
            {
                count++;
                head2 = head2->next;
            }
            
            while(head1 != NULL && head2 != NULL && head1 != head2)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            
            if(head1 != NULL && head2 != NULL)
            {
                return head1->data;
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends