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

      Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* ans = new Node(-1);
        Node* tail = ans;

        while(list1 && list2)
        {
            if(list1->data <= list2->data)
            {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }

        if(list1)
        {
            tail->next = list1;
        }
        
        if(list2)
        {
            tail->next = list2;
        }
        return ans->next;
    }

    void sort(Node **head)
    {
        Node* curr = *head;
        Node* h1=curr,*h2 = curr->next,*head1=h1,*head2=h2;
        
        while(head1 && head2)
        {
            head1->next = head2->next;
            head1 = head1->next;
            
            if(head1)
            {
                head2->next = head1->next;
                head2 = head2->next;
            }
        }
        
        h2 = reverse(h2);
        *head = mergeTwoLists(h1,h2);
    }
    
    