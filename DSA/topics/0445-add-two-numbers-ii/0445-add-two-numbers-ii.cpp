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
private:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void insertAtTail(ListNode* &head, ListNode* &tail, int val) {

        ListNode* temp = new ListNode(val);

        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    ListNode* add(ListNode* first, ListNode* second) {

        int carry = 0;

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while (first != NULL && second != NULL) {

            int sum = carry + first->val + second->val;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;

            first = first->next;
            second = second->next;
        }

        while (first != NULL) {

            int sum = carry + first->val;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;

            first = first->next;
        }

        while (second != NULL) {

            int sum = carry + second->val;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;

            second = second->next;
        }

        while (carry != 0) {

            int sum = carry;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
        }

        return ansHead;
    }

public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Step 1: Reverse input lists
        l1 = reverse(l1);
        l2 = reverse(l2);

        // Step 2: Add reversed lists
        ListNode* ans = add(l1, l2);

        // Step 3: Reverse answer
        ans = reverse(ans);

        return ans;
    }
};
/*
class Solution {                           //Time Complexity: O(n + m) Space Complexity: O(1)
public:
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}
ListNode* add(ListNode* l1, ListNode* l2) {

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {

            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Reverse both lists
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        // Add the reversed lists
        ListNode* ans = add(l1, l2);

        // Reverse the answer
        ans = reverseList(ans);

        return ans;
    }
};*/