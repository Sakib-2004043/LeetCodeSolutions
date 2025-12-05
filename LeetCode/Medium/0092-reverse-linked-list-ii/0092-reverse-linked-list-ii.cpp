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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;

        ListNode* curNode = head;
        ListNode* l1 = NULL;
        ListNode* l2 = NULL;
        ListNode* r1 = NULL;
        ListNode* r2 = NULL;
        ListNode* preNode = NULL;

        while (curNode != nullptr) {
            if (i == left - 1) {
                l1 = curNode;
            }
            if (i == left) {
                l2 = curNode;
            }
            if (i == right) {
                r1 = curNode;
            }
            if (i == right + 1) {
                r2 = curNode;
            }
            i++;
            curNode = curNode->next;
        }
        if (l1 != nullptr)
            l1->next = r1;
        curNode = l2;
        preNode = r2;
        while (curNode != r2) {
            ListNode* nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        if(head == l2){
            head = r1;
        }
        return head;
    }
};