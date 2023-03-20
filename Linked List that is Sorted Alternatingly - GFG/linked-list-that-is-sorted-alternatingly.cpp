//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function

Node* reverse(Node* head)
{
    Node* prev = NULL,*curr = head;
    while(curr != NULL)
    {
        curr = curr->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    return prev;
}


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
    if(head1->data < head2->data)
    {
        temp = head1;
        head1->next = merge(head1->next,head2);
    }
    else
    {
        temp = head2;
        head2->next = merge(head1,head2->next);
    }
    return temp;
}

void sort(Node **head)
{
    Node* temp = *head;
    if(temp == NULL || temp->next == NULL || temp->next->next == NULL)
    {
        return;
    }
    
    Node* x = *head;
    Node* y = temp->next;
    
    Node* temp1 = temp,*temp2 = temp->next->next;
    Node* curr1 = temp1->next,*curr2 = NULL;
    
    if(temp2->next)
    {
        curr2 = temp2->next;
    }
    
    while(temp2 != NULL && curr2 != NULL)
    {
        temp1->next = temp2;
        temp1= temp2;
        temp2 = curr2->next;
        
        curr1->next = curr2;
        curr1 = curr2;
        if(temp2)
        {
            curr2 = temp2->next;
        }
    }
    
    if(curr1)
    {
      curr1->next = NULL;
    }
    
    if(temp2)
    {
      temp1->next = temp2;
      temp2->next = NULL;
    }
    else
    {
        temp1->next = NULL;
    }
    
    if(x->data > x->next->data)
    {
        x = reverse(x);
        *head = merge(x,y);
    }
    else
    {
        y = reverse(y);
        *head = merge(y,x);
    }
    
    
}