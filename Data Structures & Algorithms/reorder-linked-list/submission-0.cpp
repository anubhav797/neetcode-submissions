class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;

        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at the end of first half
        ListNode* second = slow->next;
        slow->next = NULL;

        // 2. Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = second;

        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        second = prev;

        // 3. Merge both halves
        ListNode* first = head;

        while(second != NULL) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};