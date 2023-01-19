//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
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
    void reorderList(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast->next != NULL)
            {
                fast = fast->next;
            }
        }
        
        Node* mid = slow;
        
        Node* head2 = mid->next;
        mid->next = NULL;
        
        Node* prev2 = NULL;
        Node* curr2 = head2;
        
        while(curr2 != NULL)
        {
            head2 = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = head2;
        }
        
        head2 = prev2;
        Node* head1 = head;
        
        while(head1 != NULL && head2 != NULL)
        {
            Node* temp1 = head1;
            Node* temp2 = head2;
            
            head1 = head1->next;
            head2 = head2->next;
            
            temp1->next = temp2;
            temp2->next = head1;
        }
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends