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
/*
  这也是链表进行快排时，parition的思路
*/
class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* foo = new ListNode(-1);
    ListNode* bar = new ListNode(-1);
    ListNode* ret = foo;
    ListNode* tmp = bar;
    while (head) {
      if (head->val < x) {
        foo->next = head;
        foo = foo->next;
      } else {
        bar->next = head;
        bar = bar->next;
      }
      head = head->next;
    }
    bar->next = nullptr;
    foo->next = tmp->next;
    return ret->next;
  }
};