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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2;
        ListNode* head = new ListNode(0);
        
        if(ptr1 == NULL && ptr2 == NULL) {
            return NULL;
        }
        if(ptr1 == NULL) {
            return ptr2;
        }
        if(ptr2 == NULL) {
            return ptr1;
        }
    
        if(ptr1->val < ptr2->val) {
            head->val = ptr1->val;
            ptr1 = ptr1->next;
            
        }
        else {
            head->val = ptr2->val;
            ptr2 = ptr2->next;
        }
        
        head->next = mergeTwoLists(ptr1, ptr2);
        return head;
    }
};