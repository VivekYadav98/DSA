//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
        
    bool f=true;
    
    for(int i=0; i<num; i++){
        if((i==K-1) || (i==num - K)){
            if(!((before[K-1] == after[num - K]) && (before[num-K] == after[K-1]))) f=0;
        }
        else{
            if(before[i] != after[i]) f=0;
        }
    }
    
    return f;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int k)
{
        if(k>num)
        {
            return head;
        }
        
        Node* prev1 = NULL;
        Node* temp1 = head;
        int cnt = k;
        while(cnt>1 && temp1 != NULL)
        {
            prev1 = temp1;
            temp1 = temp1->next;
            cnt--;
        }
    
        Node* temp2 = head,*prev2 = NULL;
        cnt = num-k+1;
        while(cnt>1 && temp2 != NULL)
        {
            prev2 = temp2;
            temp2 = temp2->next;
            cnt--;
        }
      
        if(k <= (num/2))
        {
            if(prev1 != NULL)
            {
                prev1->next = temp2;
            }
            
            Node* x = temp2->next;
            if(temp2 != temp1->next)
            {
              temp2->next = temp1->next;
            }
            else
            {
                temp2->next = temp1;
            }
            
            if(prev2 != temp1)
            {
              prev2->next = temp1;
            }
            temp1->next = x;
            
            if(k==1)
            {
                return temp2;
            }
            return head;
        }
        else
        {
            if(prev2 != NULL)
            {
                prev2->next = temp1;
            }
        
            Node* x = temp1->next;
            
            if(temp1 != temp2->next)
            {
              temp1->next = temp2->next;
            }
            else
            {
                temp1->next = temp2;
            }
            
            if(prev1 != temp2)
            {
              prev1->next = temp2;
            }
            temp2->next = x;
            
            if(k==num)
            {
                return temp1;
            }
            return head;
        }
}

