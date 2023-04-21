#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int t;
ll P, Q;

// https://codeforces.com/contest/1444/submission/202680667
int main(int argc, char *argv[]) {

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> P >> Q;
        if (P % Q > 0) {
            cout << P << endl;
            continue;
        }
        ll ans = 0, qq = Q;
        for (int i = 2; i * i <= qq; i++) {
            if (qq % i)
                continue;
            while (qq % i == 0)
                qq /= i;
            ll pp = P;
            while (pp % Q == 0) {
                pp /= i;
            }
            ans = max(ans, pp);
        }
        // 还有没有除尽的
        if (qq > 1) {
            ll pp = P;
            while (pp % qq == 0) {
                pp /= qq;
            }
            ans = max(ans, pp);
        }
        cout << ans << endl;
    }

    return 0;
}
