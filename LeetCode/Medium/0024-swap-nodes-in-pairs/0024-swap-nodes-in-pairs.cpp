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
    ListNode* swapPairs(ListNode* head) {
        // Base case
        if (!head || !head->next)
            return head;

        // New head will be the second node
        ListNode* newHead = head->next;
        ListNode* prev = nullptr;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            // Move head for next iteration
            head = second->next;

            // Swap
            first->next = head;
            second->next = first;

            // Connect previous pair
            if (prev) {
                prev->next = second;
            }

            // Update prev
            prev = first;
        }

        return newHead;
    }
};
