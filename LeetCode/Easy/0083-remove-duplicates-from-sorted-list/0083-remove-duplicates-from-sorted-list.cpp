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
    ListNode* deleteDuplicates(ListNode* head) {
        int preVal = -200;
        ListNode* curNode = head;
        ListNode* preNode = NULL;
        while (curNode) {
            if (curNode->val == preVal) {
                preNode->next = curNode->next;
            } else {
                preNode = curNode;
                preVal = curNode->val; 
            }
            curNode = curNode->next;
        }
        return head;
    }
};