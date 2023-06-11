//{ Driver Code Starts
//

#include <bits/stdc++.h> 
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


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
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

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
       Node* temp = new Node(data);
       if(temp->data <= head->data)
       {
           Node* curr = head->next;
           head->next = temp;
           temp->next = curr;
           swap(head->data,temp->data);
           return head;
       }
       else
       {
           Node* prev = head,*curr = head->next;
           while(curr != NULL)
           {
               if(data >= prev->data && data <= curr->data)
               {
                   prev->next = temp;
                   temp->next = curr;
                   return head;
               }
               else
               {
                   prev = curr;
                   curr = curr->next;
               }
           }
           
           prev->next = temp;
           temp->next = curr;
           return head;
       }
    }
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends