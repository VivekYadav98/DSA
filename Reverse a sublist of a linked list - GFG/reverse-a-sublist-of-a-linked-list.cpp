//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
     Node* reverseL(Node* head)
    {
        Node* prev = NULL,*next = NULL,*curr = head;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* reverseBetween(Node* head, int left, int right)
    {
         Node* head1 = NULL,*temp = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt<left)
        {
            cnt++;
            prev = temp;
            temp = temp->next;
        }

        Node* curr = head;
        cnt = 1;

        while(cnt<right)
        {
            cnt++;
            curr = curr->next;
        }

        Node* temp1 = curr->next;
        curr->next = NULL;
        Node* temp2 = temp;
        head1 = reverseL(temp);

        if(prev != NULL)
        {
            prev->next = head1;
            temp2->next = temp1;
            return head;   
        }

        head->next = temp1;
        return head1;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends