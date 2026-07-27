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

    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return true;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* secondHalf = reverse(slow->next);

        // Compare both halves
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;

        while (temp != NULL) {
            if (firstHalf->val != temp->val)
                return false;

            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;
    }
};


    /*bool isPalindrome(ListNode* head) {     // tc:O(n)  SC: O(n)

        vector<int> arr;

        // Copy linked list into vector
        while (head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }

        // Check palindrome
        int i = 0;
        int j = arr.size() - 1;

        while (i < j) {
            if (arr[i] != arr[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};*/