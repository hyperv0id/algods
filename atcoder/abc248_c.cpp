// https://atcoder.jp/contests/abc248/submissions/45491377
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 998244353
#define PI 3.1415926535897932384626433832795
// types
typedef long long ll;
typedef unsigned long long ull;

// 动态规划,f[i][j] 表示i个数和 == j 的个数
int f[51][2501];

// https://atcoder.jp/contests/abc248/tasks/abc248_c
// 输入 n m(1≤n,m≤50) k(n≤k≤n*m)。
// 输出有多少个长为 n 的数组 a 满足 1≤a[i]≤m 且 sum(a)≤k。
// 模 998244353。
int main(int argc, char *argv[]) {
    int M, N, K;
    cin >> N >> M >> K;
    f[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            f[i][j] = 0;
            for (int k = max(j - M, 0); k < j; k++) { // 从 j-M 一直到 j-1
                f[i][j] += f[i - 1][k];
                f[i][j] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = N; i <= K; i++) {
        ans += f[N][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
