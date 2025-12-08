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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0, i;
        if (head->next == nullptr) {
            return NULL;
        }
        ListNode* curNode = head;
        while (curNode != nullptr) {
            num++;
            curNode = curNode->next;
        }
        num = num - n + 1;
        cout << num << endl;
        //
        curNode = head;
        i = 1;
        while (curNode != nullptr) {
            if (num == 1) {
                return curNode->next;
            }
            if (i == num - 1) {

                if (curNode->next != nullptr) {
                    curNode->next = curNode->next->next;
                } else {
                    curNode->next == NULL;
                }
                goto ff;
            }
            i++;
            curNode = curNode->next;
        }
    ff:;
        return head;
    }
};