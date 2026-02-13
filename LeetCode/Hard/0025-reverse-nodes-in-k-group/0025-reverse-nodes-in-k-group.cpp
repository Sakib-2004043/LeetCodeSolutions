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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }
        stack<ListNode*> st;
        ListNode* cur = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* preNode = dummy;
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->next;
            if (st.size() == k) {
                ListNode* nextGroup = cur; // remember where next group starts
                while (!st.empty()) {
                    ListNode* node = st.top();
                    st.pop();
                    preNode->next = node; // link from previous
                    preNode = node;
                    if (st.empty()) {
                        node->next = nextGroup; // connect to remaining part
                    }
                }
            }
        }
        return dummy->next;
    }
};