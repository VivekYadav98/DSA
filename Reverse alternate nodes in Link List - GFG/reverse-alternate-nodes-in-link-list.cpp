//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* curr = head,*prev = NULL;
        while(curr != NULL)
        {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        
        return prev;
    }
    
    void rearrange(struct Node *head)
    {
        Node* h1 = head,*head1 = head,*h2 = head->next,*head2 = head->next;
        
        while(head1 != NULL && head2 != NULL)
        {
            head1->next = head2->next;
            head1 = head1->next;
            
            if(head1 != NULL)
            {
                head2->next = head1->next;
                head2 = head2->next;
            }
        }
        
        head1 = h1;
        while(head1->next != NULL)
        {
            head1 = head1->next;
        }
        
        head2 = reverse(h2);
        head1->next = head2;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends