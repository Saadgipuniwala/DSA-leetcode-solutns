class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL)
            return head;

        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {

            if (curr->val == curr->next->val) {

                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;

            } else {

                curr = curr->next;
            }
        }

        return head;
    }
};