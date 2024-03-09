#include <bits/stdc++.h>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

ll A[MAX_SIZE];
ll dp[MAX_SIZE];

// https://codeforces.com/contest/455/submission/250290532
int main(int argc, char *argv[]) {
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        int n, x;
        cin >> n;
        _rep(i, 0, n - 1) {
            cin >> x;
            A[x]++;
        }
        // Solution
        dp[1] = A[1];
        dp[2] = A[2] * 2;
        for (ll i = 3; i < MAX_SIZE; ++i) {
            dp[i] = max(dp[i - 3], dp[i - 2]) + i * A[i];
        }
        ll ans = 0;
        for (int i = 0; i < MAX_SIZE; ++i) {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
