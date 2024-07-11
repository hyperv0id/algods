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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// https://leetcode.cn/problems/add-two-numbers/submissions/545556756?envType=study-plan-v2&envId=top-100-liked
// 2. 两数相加
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int rem = 0;
    ListNode *head = new ListNode();
    ListNode *cur = head;
    while (l1 || l2) {
      if (l1) {
        rem += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        rem += l2->val;
        l2 = l2->next;
      }
      auto last = new ListNode(rem % 10);
      cur->next = last;
      cur = cur->next;
      rem /= 10;
    }
    if (rem != 0)
      cur->next = new ListNode(rem);
    return head;
  }
};
