//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*
// structure of the node is as follows

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
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        vector<int>arr1,arr2,temp;
        while(head1 != NULL)
        {
            arr1.push_back(head1->data);
            head1 = head1->next;
        }
        
        while(head2 != NULL)
        {
            arr2.push_back(head2->data);
            head2 = head2->next;
        }
        
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int n1 = arr1.size(),n2 = arr2.size();
        int i=0,j=0;
        
        while(i<n1 && j<n2)
        {
            while(i+1<n1 && arr1[i] == arr1[i+1])
            {
                i++;
            }
            
            while(j+1<n2 && arr2[j] == arr2[j+1])
            {
                j++;
            }
            
            if(arr1[i] < arr2[j])
            {
                temp.push_back(arr1[i]);
                i++;
            }
            else if(arr2[j] < arr1[i])
            {
                temp.push_back(arr2[j]);
                j++;
            }
            else
            {
                temp.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        
        while(i<n1)
        {
            if(i+1<n1 && arr1[i] == arr1[i+1])
            {
                i++;
            }
            else
            {
                temp.push_back(arr1[i]);
                i++;
            }
        }
        
        while(j<n2)
        {
            if(j+1<n2 && arr2[j] == arr2[j+1])
            {
                j++;
            }
            else
            {
                temp.push_back(arr2[j]);
                j++;
            }
        }
        
        Node* ans = new Node(-1);
        Node* tail = ans;
        for(int i=0;i<temp.size();i++)
        {
            tail->next = new Node(temp[i]);
            tail = tail->next;
        }
        return ans->next;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends