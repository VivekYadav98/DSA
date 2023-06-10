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

Node* findMid(Node* head)
    {
        Node* slow = head,*fast = head;

        while(fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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

    Node* sortList(Node* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        Node* mid = findMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);
        Node* res = mergeTwoLists(left,right);
       
        return res;
    }

    void sort(Node **head)
    {
         Node* curr = *head;
        *head = sortList(curr);
    }