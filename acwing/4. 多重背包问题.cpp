
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1005;

int v[MAX_SIZE], w[MAX_SIZE], dp[MAX_SIZE];

void solve(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= v[i]) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[m] << endl;
}
int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N, V;
    cin >> N >> V;

    for (size_t i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    solve(N, V);
    return 0;
}
