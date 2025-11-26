class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, n;
        vector<int> v;
        // n = lists.size();

        for (auto head : lists) {
            while (head != nullptr) {
                v.push_back(head->val);
                head = head->next;
            }
        }

        sort(v.begin(),v.end());

        ListNode* newHead = NULL;
        ListNode* curNode = NULL;
        
        for(auto x:v){
            if(newHead == NULL){
                newHead = new ListNode();
                newHead->val = x;
                newHead->next = NULL;
                curNode = newHead;
            }
            else{
                ListNode* newNode = new ListNode();
                newNode->val=x;
                newNode->next=NULL;
                curNode->next=newNode;
                curNode = newNode;
            }
            
        }
        return newHead;
    }
};
