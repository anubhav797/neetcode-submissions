class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        while(temp1 != NULL || temp2 != NULL) {

            int sum = carry;

            if(temp1) {
                sum = sum + temp1->val;
            }

            if(temp2) {
                sum = sum + temp2->val;
            }

            // Create node with unit digit
            ListNode* newNode = new ListNode(sum % 10);

            // Store carry
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;

            if(temp1) {
                temp1 = temp1->next;
            }

            if(temp2) {
                temp2 = temp2->next;
            }
        }

        // If carry is still left
        if(carry) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        return dummyHead->next;
    }
};