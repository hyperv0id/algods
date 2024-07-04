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
// https://leetcode.cn/problems/linked-list-cycle/submissions/543929047?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if(head == nullptr) return false;
    ListNode *fast, *slow;
    fast = slow = head;
    fast = fast->next;
    if(!fast) return false;
    fast = fast->next;
    slow = slow->next;
    while (fast && slow && fast != slow) {
      fast = fast->next;
    if(!fast) return false;
      fast = fast->next;
      slow = slow->next;
    }
    return fast != nullptr;
  }
};
