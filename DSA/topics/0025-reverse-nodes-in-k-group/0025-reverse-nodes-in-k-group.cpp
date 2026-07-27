class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL)
            return NULL;

        // Check if at least k nodes exist
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;
            temp = temp->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        int count = 0;
        // reversing begins
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};