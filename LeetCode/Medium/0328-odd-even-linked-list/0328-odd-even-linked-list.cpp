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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddNode = new ListNode(0);
        ListNode* evnNode = new ListNode(0);
        ListNode* evnHead = evnNode;
        ListNode* curNode = head;
        int k = 1;
        while (curNode != nullptr) {
            ListNode* nxtNode = curNode->next;
            if (k % 2) {
                oddNode->next = curNode;
                oddNode = curNode;
                oddNode->next = NULL;
            }
            else{
                evnNode->next = curNode;
                evnNode = curNode;
                evnNode->next = NULL;
            }
            curNode = nxtNode;
            k++;
        }
        oddNode->next = evnHead->next;
        return head;
    }
};