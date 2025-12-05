/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> rand;

        Node* preNode = NULL;
        Node* newHead = NULL;

        Node* curNode = head;

        while (curNode != nullptr) {
            Node* newNode = new Node(curNode->val);
            newNode->next = NULL;
            if(newHead == NULL){
                newHead = newNode;
            }
            rand[curNode] = newNode;
            if(preNode != NULL){
                preNode->next = newNode;
            }
            preNode = newNode;

            curNode = curNode->next;
        }
        
        curNode = head;
        while(curNode != nullptr){
            rand[curNode]->random = rand[curNode->random];
            curNode = curNode->next;
        }

        return newHead;
    }
};