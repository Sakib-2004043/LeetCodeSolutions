class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, temp;
        ListNode* sumHead = NULL;
        ListNode* curNode = NULL;
        ListNode* remNode = NULL;
        while (l1 != nullptr && l2 != nullptr) {
            temp = l1->val + l2->val + carry;
            if (temp > 9) {
                carry = 1;
                temp %= 10;
            } else {
                carry = 0;
            }

            if (sumHead == NULL) {
                sumHead = new ListNode();
                sumHead->val = temp;
                sumHead->next = NULL;
                curNode = sumHead;
            } else {
                ListNode* newNode = new ListNode();
                newNode->val = temp;
                newNode->next = NULL;
                curNode->next = newNode;
                curNode = newNode;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 != nullptr && l2 != nullptr){
            return sumHead;
        }
        else if(l1 != nullptr){
            remNode = l1;
        }
        else {
            remNode = l2;
        }
        while (remNode != nullptr) {
            temp = remNode->val + carry;
            if (temp > 9) {
                carry = 1;
                temp %= 10;
            } else {
                carry = 0;
            }

            ListNode* newNode = new ListNode();
            newNode->val = temp;
            newNode->next = NULL;
            curNode->next = newNode;
            curNode = newNode;
            
            remNode = remNode->next;
        }

        if(carry){
            ListNode* newNode = new ListNode();
            newNode->val = carry;
            newNode->next = NULL;
            curNode->next = newNode;
        }
        return sumHead;
    }
};
