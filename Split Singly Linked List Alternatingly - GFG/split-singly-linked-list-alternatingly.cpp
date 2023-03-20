//{ Driver Code Starts

#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void append(struct Node** headRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)last = last->next;
	last->next = new_node;
}

void printList(struct Node *node)
{
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
} 

void alternatingSplitList(struct Node*); 

struct Node* a;
struct Node* b;

int main()
{
    int test;
    cin>>test;
    
    while(test--)
    {
        a=b=NULL;
        struct Node* head = NULL;
        
        
        int n, k;
        cin>>n;
        
        while(n--)
        {
            cin>>k;
            append(&head, k);
        }
        
        alternatingSplitList(head);
        printList(a);
        printList(b);
    }
    return 0;
}




// } Driver Code Ends


/*
structure of node is as
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/


/*
These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list

*/

void alternatingSplitList(struct Node* head) 
{
    Node* temp = head;
    Node* x = temp;
    if(temp == NULL || temp->next == NULL)
    {
        a = temp;
        b = NULL;
        return;
    }
    if(temp->next->next == NULL)
    {
        b = temp->next;
        temp->next = NULL;
        a = temp;
        return;
    }
    
    Node* temp1 = head,*temp2 = head->next->next;
    Node* curr1 = temp1->next,*curr2 = NULL;temp = curr1;
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
    
    a = x;
    b = temp;
}

