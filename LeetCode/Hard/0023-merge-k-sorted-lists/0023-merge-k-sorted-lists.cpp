class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;

        // Step 1: collect all values
        for (auto head : lists) {
            while (head) {
                v.push_back(head->val);
                head = head->next;
            }
        }

        if (v.empty()) return nullptr; // handle empty input

        // Step 2: sort values
        sort(v.begin(), v.end());

        // Step 3: build new linked list efficiently
        ListNode* newHead = new ListNode(v[0]); // directly set value
        ListNode* curNode = newHead;

        for (size_t i = 1; i < v.size(); ++i) {
            curNode->next = new ListNode(v[i]); // create node with value
            curNode = curNode->next;
        }

        return newHead;
    }
};
