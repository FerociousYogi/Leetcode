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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int len = 0;
        
        ListNode* ptr = head;
        while(ptr->next) {
            len++;
            ptr = ptr->next;
        }
        len += 1;
        
        k = k % len;
        k = len - k;
        
        ptr->next = head;
        for(int i = 0; i < k; i++) {
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = NULL;
        
        return head;
    }
};