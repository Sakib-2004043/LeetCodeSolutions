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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* curNode = head;
        while (curNode != nullptr) {
            nodes.push_back(curNode);
            curNode = curNode->next;
        }
        ListNode* preNode = NULL;
        int n = nodes.size();
        for (int i = 0; i < n/2 + n%2; i++) {
            nodes[i]->next = nodes[n - i - 1];
            nodes[n - i - 1]->next = NULL;
            if (preNode != nullptr) {
                preNode->next = nodes[i];
            }
            preNode = nodes[n - i - 1];
        }
    }
};