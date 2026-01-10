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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* revHead = new ListNode(head->val);
        revHead->next = NULL;

        while (head != nullptr) {
            head = head->next;
            if (head != nullptr) {
                ListNode* curNode = new ListNode(head->val);
                curNode->next = revHead;
                revHead = curNode;
            }
        }
        return revHead;
    }
};