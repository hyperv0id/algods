#include <bits/stdc++.h>

using namespace std;

void solve(int n, int v) {
    vector<int> av(n + 1), aw(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> av[i] >> aw[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(v + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v; j++) {
            // 如果能装下就直接拿
            // 如果不能装下就选前 i 个
            if (j < av[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - av[i]] + aw[i]);
            }
        }
    }
    cout << dp[n][v] << endl;
}

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N, V;
    cin >> N >> V;
    solve(N, V);
    return 0;
}
