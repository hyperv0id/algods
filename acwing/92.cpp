
#include <bits/stdc++.h>
// https://www.acwing.com/problem/content/92/
// https://www.acwing.com/problem/content/submission/code_detail/35076949/

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

ll a, b, p;

int add(ll a, ll b, ll p) {
    ll t = a;
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * t) % p;
        }
        t = (t * t) % p;
        b >>= 1;
    }
    return ans % p;
}

int main(int argc, char *argv[]) {
    // 必须加速读
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int h, m, a, b;
        cin >> m >> h;
        ll ans = 0;
        while (h--) {
            cin >> a >> b;
            ans += add(a, b, m);
        }
        cout << ans % m << endl;
    }
    return 0;
}
