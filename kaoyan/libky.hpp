#include <bits/stdc++.h>
#include <cstdarg>
using namespace std;
struct linkedList {
    int val;
    linkedList *next;
    linkedList(int val) { this->val = val; }
};
linkedList *mklinked(int cnt, ...) {
    va_list v;
    va_start(v, cnt);
    linkedList *head = new linkedList(0);
    linkedList *p = head;
    for (int i = 0; i < cnt; ++i) {
        p->next = new linkedList(va_arg(v, int));
        p = p->next;
    }
    return head->next;
}

void print_list(linkedList *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
