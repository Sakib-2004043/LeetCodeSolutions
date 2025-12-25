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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return NULL;
        }
        int sz = 1;
        ListNode* curNode = head;
        ListNode* preNode = NULL;
        while (curNode->next != nullptr) {
            sz++;
            curNode = curNode->next;
        }
        curNode->next = head;
        k = k % sz;
        curNode = head;
        int i = sz;
        while (curNode != nullptr) {
            if (i == k) {
                preNode->next = NULL;
                head = curNode;
            }
            preNode = curNode;
            curNode = curNode->next;
            i--;
        }
        return head;
    }
};