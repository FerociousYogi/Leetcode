class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* ptr = head;
        ListNode* before = new ListNode();
        before->next = head;
        ListNode* after = head;
        
        for(int i = 0; i < m-1; i++) {
            before = ptr;
            ptr = ptr->next;
        }
                        
        for(int i = 0; i < n-m+1; i++) {
            ptr = ptr->next;
            after = ptr;
        }
    
        ListNode* newhead = before->next;
        before->next = reverseList(newhead, n-m+1);
        
        ListNode* temp = before->next;
        for(int i = 0; i < n-m; i++) {
            temp = temp->next;
        }
        temp->next = after;
        
        if (m == 1) return before->next;
        return head;
    }
    
    ListNode* reverseList(ListNode* head, int len) {
        ListNode *prev, *curr, *next;
        curr = head;
        next = head;
        prev = nullptr;
        
        for(int i = 0; i < len; i++) {
            curr = next;
            next = curr->next;
            curr->next = prev;
            prev = curr;
        }
        
        cout << curr->val << endl;
        
        return curr;
    }
};