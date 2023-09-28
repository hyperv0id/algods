#include "libky.hpp"
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
// 给定俩有序链表，给链表合并+去重
linkedList *solve(linkedList *l1, linkedList *l2) {
    linkedList *head = new linkedList(0), *p;
    p = head;
    // 1. 合并
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = new linkedList(l1->val);
            l1 = l1->next;
        } else {
            p->next = new linkedList(l2->val);
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1) {
        p->next = l1;
    }
    if (l2) {
        p->next = l2;
    }
    // 2. 去重
    p = head;
    while (p && p->next) {
        if (p->val == p->next->val) {
            p->next = p->next->next;
        }
        p = p->next;
    }

    return head->next;
}

int main(int argc, char *argv[]) {
    {
        auto l1 = mklinked(5, 1, 2, 3, 4, 5);
        // print_list(l1);
        auto l2 = mklinked(4, 5, 6, 7, 8);
        // print_list(l2);
        auto ans = solve(l1, l2);
        print_list(ans);
    }
    {
        auto l1 = mklinked(5, 1, 2, 3, 4, 5);
        // print_list(l1);
        auto l2 = mklinked(4, 1, 2, 4, 5);
        // print_list(l2);
        auto ans = solve(l1, l2);
        print_list(ans);
    }
    return 0;
}
