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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* headptr = head->next;
        ListNode* ptr = head->next->next;
        
        head->next->next = head;
        ListNode* toBeAttached = swapPairs(ptr);
        head->next = toBeAttached;
        return headptr;
    }
};