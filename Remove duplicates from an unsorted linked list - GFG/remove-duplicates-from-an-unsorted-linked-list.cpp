//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
       if(head == NULL || head->next == NULL)
       {
           return head;
       }
       
       Node* temp1 = head;
       Node* temp2 = head->next;
       unordered_set<int>s;
       s.insert({temp1->data});
       
       while(temp2 != NULL)
       {
           if(temp1->data == temp2->data)
           {
               temp2 = temp2->next;
               temp1->next = temp2;
           }
           else if(s.find(temp2->data) == s.end())
           {
               s.insert({temp2->data});
               temp1 = temp1->next;
               temp2 = temp2->next;
           }
           else if(s.find(temp2->data) != s.end())
           {
                temp2 = temp2->next;
                temp1->next = temp2;
           }
           else
           {
               temp2 = temp2->next;
               temp1 = temp1->next;
           }
       }
       return head;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends