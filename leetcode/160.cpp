#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB){return headA;}
        ListNode* na = headA, *nb = headB;
        while(nb != na){
            na = na==nullptr?headB:na->next;
            nb = nb==nullptr?headA:nb->next;
        }
        return na;
    }
};
