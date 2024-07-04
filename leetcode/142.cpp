#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// https://leetcode.cn/problems/linked-list-cycle-ii/submissions/543930418
class Solution {
public:
  const int MIN = -1e7;
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    ListNode *cur = head;
    ListNode *ans;
    while (cur != nullptr) {
      if (cur->val < MIN) {
        redo(head);
        return cur;
      }
      cur->val += MIN * 2;
      cur = cur->next;
    }
    return nullptr;
  }
  void redo(ListNode *head) {
    while (head->val < MIN) {
      head->val -= MIN * 2;
    }
  }
};
