//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
    
    struct Node* modifyTheList(struct Node *head)
    {
        Node* slow = head,*fast = head;
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* head2 = slow->next;
        slow->next = NULL;
        Node* head1 = head;
        
        head2 = reverse(head2);
        Node* h1 = head1;
        Node* h2 = head2;
        
        while(head1 != NULL && head2 != NULL)
        {
            head1->data = head2->data - head1->data;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        
        head1 = h1,head2 = h2;
        Node* prev1 = head1,*prev2 = head2;
        
        while(head1 != NULL && head2 != NULL)
        {
            head2->data = head2->data - head1->data;
            head2 = head2->next;
            prev1 = head1;
            head1 = head1->next;
        }
        
        head2 = reverse(h2);
        
        if(head1 == NULL)
        {
            prev1->next = head2;
        }
        else
        {
            head1->next = head2;
        }
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends