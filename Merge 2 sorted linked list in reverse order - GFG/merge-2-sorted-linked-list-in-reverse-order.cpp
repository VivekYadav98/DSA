//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

Node* merge(Node* head1,Node* head2)
{
    if(head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head1;
    }
    
    Node* temp = NULL;
    if(head1->data > head2->data)
    {
        temp = head1;
        temp->next = merge(head1->next,head2);
    }
    else
    {
        temp = head2;
        temp->next = merge(head1,head2->next);
    }
    return temp;
}

Node* reverse(Node* head)
{
    Node* prev=NULL,*curr=head;
    while(curr)
    {
        curr = curr->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    return prev;
}

struct Node * mergeResult(Node *node1,Node *node2)
{
    Node* head1 = reverse(node1);
    Node* head2 = reverse(node2);
    
    Node* ans = merge(head1,head2);
    return ans;
}