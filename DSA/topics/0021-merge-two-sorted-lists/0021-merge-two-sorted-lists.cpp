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
    /* ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(list1 != NULL && list2 != NULL){

            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if(list1)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
        }
}; */

    void solve(ListNode* first, ListNode* second) {

    ListNode* curr1 = first;
    ListNode* next1 = curr1->next;

    ListNode* curr2 = second;
    ListNode* next2 = NULL;

    // Handle single-node first list
    if (next1 == NULL) {
        curr1->next = curr2;
        return;
    }

    while (next1 != NULL && curr2 != NULL) {

            if ((curr2->val >= curr1->val) &&
                (curr2->val <= next1->val)) {

                // Insert curr2 between curr1 and next1
                next2 = curr2->next;
                curr1->next = curr2;
                curr2->next = next1;

                // Move pointers
                curr1 = curr2;
                curr2 = next2;
            }
            else {

                curr1 = next1;
                next1 = next1->next;

                if (next1 == NULL) {
                    curr1->next = curr2;
                    return;
                }
            }
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        // Make sure list1 starts with the smaller element
        if (list1->val <= list2->val) {
            solve(list1, list2);
            return list1;
        }
        else {
            solve(list2, list1);
            return list2;
        }
    }
};
