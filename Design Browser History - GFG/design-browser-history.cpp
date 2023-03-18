//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct Node{
        string data;
        Node* next;
        Node* prev;
        Node(string data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class BrowserHistory {
public:   
    Node* head;
    BrowserHistory(string homepage) {
       head = new Node(homepage);
    }
    
    void visit(string url) {
       Node* newNode = new Node(url);
       head->next = newNode;
       newNode->prev = head;
       head = newNode;
    }
    
    string back(int steps) {
        while(steps>0 && head->prev != NULL)
        {
            head = head->prev;
            steps--;
        }
        return head->data;
    }
    
    string forward(int steps) {
        while(steps>0 && head->next != NULL)
        {
            head = head->next;
            steps--;
        }
        return head->data;
    }
};


//{ Driver Code Starts.

int main()
{
    string homepage;
    cin >> homepage;
    
    BrowserHistory obj(homepage);
    
    int total_queries;
    cin >> total_queries;
    while(total_queries--)
    {
        int query;
        cin >> query;
        
        // if query = 1, visit()
        // if query = 2, back()
        // if query = 3, forward()
        
        if(query == 1) {
            string url;
            cin >> url;
            obj.visit(url);
        }
        else if(query == 2) {
            int steps;
            cin >> steps;
            cout << obj.back(steps) << endl;
        }
        else {
            int steps;
            cin >> steps;
            cout << obj.forward(steps) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends