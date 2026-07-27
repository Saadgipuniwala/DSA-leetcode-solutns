
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

    ListNode* findMid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {

        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while (left != NULL && right != NULL) {

            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        return ans->next;
    }

    ListNode* sortList(ListNode* head) {

        // Base Case
        if (head == NULL || head->next == NULL)
            return head;

        // Find Mid
        ListNode* mid = findMid(head);

        // Divide into two halves
        ListNode* left = head;
        ListNode* right = mid->next;

        mid->next = NULL;

        // Recursive Sort
        left = sortList(left);
        right = sortList(right);

        // Merge Sorted Lists
        return merge(left, right);
    }
};