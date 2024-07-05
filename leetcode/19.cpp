#include <bits/stdc++.h>

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
// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/submissions/544175157?envType=study-plan-v2&envId=top-100-liked
// 19. 删除链表的倒数第 N 个结点
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {

    ListNode *pre = new ListNode();
    pre->next = head;
    ListNode *fast = pre, *slow = pre;
    while (n--) {
      fast = fast->next;
    }
    while (fast && fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return pre->next;
  }
};
