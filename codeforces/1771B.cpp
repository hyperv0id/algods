#include <bits/stdc++.h>
#include <cstdio>
#include <utility>

using namespace std;
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

// https://codeforces.com/contest/1771/submission/245042309
ll solve() {
    int m, n, x, y;
    scanf("%d %d", &n, &m);
    vector<int> L(n + 1, 0);
    while (m--) {
        scanf("%d %d", &x, &y);
        if (x > y)
            swap(x, y);
        L[y] = max(L[y], x);
    }
    ll ans = 0;
    int maxL = 0;
    for (int i = 0; i <= n; i++) {
        maxL = max(maxL, L[i]);
        ans += i - maxL;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        cout << solve() << endl;
    }
    return 0;
}
