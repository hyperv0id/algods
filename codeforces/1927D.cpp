#include <stdio.h>
#include<vector>

// https://codeforces.com/contest/1927/submission/269892736
// 样例有误 
int main() {
    int tc, n, pre, v, q, l, r;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &pre);
        std::vector<int> left_(n+1);
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &v);
            if (v == pre) {
                left_[i] = left_[i - 1];
            } else {
                left_[i] = i - 1;
            }
            pre = v;
        }
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d", &l, &r);
            if (left_[r] < l) {
                printf("-1 -1\n");
            } else {
                printf("%d %d\n", left_[r], r);
            }
        }
    }
    return 0;
}
