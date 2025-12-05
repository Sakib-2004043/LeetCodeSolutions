/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* cur = head;

        // 1. Interleave cloned nodes with original nodes
        while (cur) {
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }

        // 2. Set random pointers for cloned nodes
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // 3. Separate the two lists
        cur = head;
        Node* newHead = head->next;
        Node* clone = newHead;

        while (cur) {
            cur->next = cur->next->next;
            if (clone->next)
                clone->next = clone->next->next;
            cur = cur->next;
            clone = clone->next;
        }

        return newHead;
    }
};
