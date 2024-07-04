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
// https://leetcode.cn/problems/reverse-linked-list/submissions/543924047?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if(head == nullptr)return nullptr;
    ListNode* pre = nullptr;
    ListNode* now = head;
    ListNode* tmp = nullptr;
    while (now) {
      tmp = now->next;
      now->next = pre;
      pre = now;
      now = tmp;
    }
    return pre;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
