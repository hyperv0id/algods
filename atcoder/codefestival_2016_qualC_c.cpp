#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

int n;
int b[MAX_SIZE], c[MAX_SIZE], a[MAX_SIZE];

// https://atcoder.jp/contests/code-festival-2016-qualc/submissions/45689000
ll solve() {
    ll ans = 1;
    for (int i = 0; i < n; i++) {

        bool bok = i != 0 && b[i] <= b[i - 1];
        bool cok = i != n - 1 && c[i] <= c[i + 1];
        if (bok && cok) {
            ans = ans * min(b[i], c[i]) % MOD;
        }
        // fprintf(stderr, "%d %d %d %d\n", bok, cok, b[i], c[i]);
        if ((!bok && b[i] > c[i]) || (!cok && b[i] < c[i])) {
            return 0;
        }
    }
    return ans;
}
int main(int argc, char *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    cout << solve() << endl;
    return 0;
}
