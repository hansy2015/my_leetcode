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
    Node* newHead = new Node(-1);
    Node* cur = newHead;
    Node* useHead = head;
    while (useHead) {
        cur->next = new Node(useHead->val);
        cur = cur->next;
        useHead = useHead->next;
    }
    map<Node*,Node*> mp;
    useHead = head;
    cur = newHead->next;
    while (useHead) {
        mp[useHead] = cur;
        useHead = useHead->next;
        cur = cur->next;
    }
    useHead = head;
    cur = newHead->next;
    while (useHead) {
        cur->random = mp[useHead->random];
        useHead = useHead->next;
        cur = cur->next;
    }
    return newHead->next;
  }
};