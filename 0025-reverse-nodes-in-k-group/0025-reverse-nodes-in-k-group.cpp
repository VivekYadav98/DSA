/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* prev = NULL;
        ListNode* next= NULL;
        ListNode* curr = head;
    
        while(count<k && curr!=NULL)
        {
            next =  curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
       
        if(next != NULL)
        {
           ListNode* restHead = reverseKGroup(next,k);
            head->next = restHead;
        }
        
        if(next == NULL && count<k)
        {
            ListNode* curr1 = prev;
            ListNode* prev1 = NULL;
            ListNode* head1 = prev;
            
            while(curr1 != NULL)
            {
                head1 = curr1->next;
                curr1->next = prev1;
                prev1 = curr1;
                curr1 = head1;
            }
            return prev1;
        } 
        return prev;
    }
};