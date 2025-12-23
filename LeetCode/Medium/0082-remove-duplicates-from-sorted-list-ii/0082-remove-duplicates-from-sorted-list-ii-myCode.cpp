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
        ListNode* root = NULL;
        ListNode* preNode = NULL;
        while (head != nullptr) {
            bool entered = false;
            while (head->next != nullptr && head->val == head->next->val) {
                head = head->next;
                entered = true;
                if(preNode!=nullptr){
                    preNode->next=NULL;
                }
            }
            if (entered) {
                head = head->next;
                continue;
            }
            if (root == NULL) {
                root = head;
                preNode = root;
            } else {
                preNode->next = head;
                preNode = head;
            }
            head = head->next;
        }
        return root;
    }
};