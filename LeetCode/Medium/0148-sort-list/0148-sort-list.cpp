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
    ListNode* sortList(ListNode* head) {
        vector<pair<int, ListNode*>> sorter;
        while (head != nullptr) {
            sorter.push_back({head->val, head});
            head = head->next;
        }
        sort(sorter.begin(),sorter.end());
        ListNode* prevNode = NULL;
        ListNode* rootNode = NULL;
        bool flag = true;
        for (auto node : sorter) {
            node.second->next = NULL;
            if (flag) {
                rootNode = node.second;
                prevNode = rootNode;
                flag = false;
            } else {
                prevNode->next = node.second;
                prevNode = node.second;
            }
        }
        return rootNode;
    }
};