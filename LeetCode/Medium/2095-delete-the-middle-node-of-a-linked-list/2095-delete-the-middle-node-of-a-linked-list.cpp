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
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int totalNode = 0;
        ListNode* curNode = head;
        while (curNode != nullptr) {
            totalNode++;
            curNode = curNode->next;
        }
        if (totalNode == 1) {
            return nullptr;
        }
        int midNode = totalNode / 2;
        curNode = head;
        while (curNode != nullptr) {
            midNode--;
            if (midNode == 0) {
                curNode->next = curNode->next->next;
            }
            curNode = curNode->next;
        }
        return head;
    }
};