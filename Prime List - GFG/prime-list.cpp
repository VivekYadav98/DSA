//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    int solve(int num,vector<bool>& prime)
    {
        int num1 = num-1;
        int num2 = num+1;
        
        while(true)
        {
            if(prime[num1] == true && prime[num2] == true)
            {
                return num1;
            }
            else if(prime[num1] == true)
            {
                return num1;
            }
            else if(prime[num2] == true)
            {
                return num2;
            }
            else
            {
                num1--;
                num2++;
            }
        }
    }
    Node *primeList(Node *head){
        vector<bool>prime(100001,true);
        prime[0] = prime[1] = false;
        
        for(int i=2;i*i<=100001;i++)
        {
            if(prime[i] == true)
            {
                for(int j=2*i;j<=100001;j+=i)
                {
                    prime[j] = false;
                }
            }
        }
        
        Node* temp = head;
        while(temp != NULL)
        {
            if(prime[temp->val] == false)
            {
                int data = solve(temp->val,prime);
                temp->val = data;
            }
            temp = temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends