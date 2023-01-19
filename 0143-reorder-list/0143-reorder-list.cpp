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
    void reorderList(ListNode* head) {
         ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast->next != NULL)
            {
                fast = fast->next;
            }
        }
        
        ListNode* mid = slow;
        
        ListNode* head2 = mid->next;
        mid->next = NULL;
        
        ListNode* prev2 = NULL;
        ListNode* curr2 = head2;
        
        while(curr2 != NULL)
        {
            head2 = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = head2;
        }
        
        head2 = prev2;
        ListNode* head1 = head;
        
        while(head1 != NULL && head2 != NULL)
        {
            ListNode* temp1 = head1;
            ListNode* temp2 = head2;
            
            head1 = head1->next;
            head2 = head2->next;
            
            temp1->next = temp2;
            temp2->next = head1;
        }
    }
};