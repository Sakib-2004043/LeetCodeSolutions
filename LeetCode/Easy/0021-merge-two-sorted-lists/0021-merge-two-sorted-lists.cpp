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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int i, n;
        vector<int> v;
        while (list1 != nullptr) {
            v.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            v.push_back(list2->val);
            list2 = list2->next;
        }
        if (!v.size()) {
            return NULL;
        }
        sort(v.begin(), v.end());

        ListNode* preNode = new ListNode(v[0]);
        preNode->next = NULL;
        ListNode* rootNode = preNode;

        n = v.size();
        for (i = 1; i < n; i++) {
            ListNode* curNode = new ListNode(v[i]);
            curNode->next = NULL;
            preNode->next = curNode;
            preNode = curNode;
        }
        return rootNode;
    }
};