// 91. 最短Hamilton路径
// https://www.acwing.com/problem/content/submission/code_detail/27584202/

#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
#define endl '\n'

const int N = 20, M = 1 << 20;
int f[M][N];

// types
typedef long long ll;
typedef unsigned long long ull;

int solve(vector<vector<int>> &weight, int n) {
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) % 2 == 0)
                continue;
            // 从 state_k 转移到 state_j
            // 此时包含k但不包含j
            for (int k = 0; k < n; k++)
                if (i >> k & 1) {
                    f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);
                    // cerr << i << " " << j << " " << f[i][j] << endl;
                }
        }
    }
    return f[(1 << n) - 1][n - 1]; // 遍历所有的点，最后停在n-1这个点
}

int main(int argc, char *argv[]) {
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> weight(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> weight[i][j];
            }
        }

        memset(f, 0x3f, sizeof(f));
        f[1][0] = 0;

        cout << solve(weight, n) << endl;
    }
    return 0;
}
