/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        
       ListNode* intersection = NULL;
       ListNode* slow = head;
       ListNode* fast = head;
       
       while(fast != NULL)
       {
           slow = slow->next;
           fast = fast->next;
           
           if(fast != NULL)
           {
               fast = fast->next;
           }
           
           if(slow == fast)
           {
               intersection = slow;
               break;
           }
       }
       
       if(intersection == NULL)
       {
           return NULL;
       }
       
       slow = head;
       fast = intersection;
       
       while(slow != fast)
       {
           slow = slow->next;
           fast = fast->next;
       }
       return slow;
    }
};