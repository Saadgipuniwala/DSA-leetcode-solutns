/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:

    void insertAtTail(Node* &head, Node* &tail, int val) {

        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:

    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        // Step 1: Create Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // Step 2: Insert clone nodes between original nodes
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL) {

            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        // Step 3: Copy random pointers
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL) {

            if (originalNode->random != NULL)
                cloneNode->random = originalNode->random->next;
            else
                cloneNode->random = NULL;

            originalNode = cloneNode->next;

            if (originalNode != NULL)
                cloneNode = originalNode->next;
        }

        // Step 4: Separate the two lists
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL) {

            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL)
                cloneNode->next = originalNode->next;
            else
                cloneNode->next = NULL;

            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};