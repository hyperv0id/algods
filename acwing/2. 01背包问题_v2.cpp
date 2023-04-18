#include <bits/stdc++.h>

using namespace std;

// 转换成 一维，节省空间
void solve(int n, int v) {
    vector<int> av(n + 1), aw(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> av[i] >> aw[i];
    }
    vector<int> next(v + 1), cur(v + 1);
    for (int i = 1; i <= n; i++) {
        next = vector<int>(v + 1);
        for (int j = 1; j <= v; j++) {
            // 如果能装下就直接拿
            // 如果不能装下就选前 i 个
            next[j] = cur[j];
            if (j >= av[i])
                next[j] = max(next[j], cur[j - av[i]] + aw[i]);
        }
        cur = next;
    }
    cout << cur[v] << endl;
}

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N, V;
    cin >> N >> V;
    solve(N, V);
    return 0;
}
