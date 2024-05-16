#include <bits/stdc++.h>
// https://www.acwing.com/problem/content/91/
// https://www.acwing.com/problem/content/submission/code_detail/35076706/

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

ll a, b, p;

int main(int argc, char *argv[]) {
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        cin >> a >> b >> p;
        ll t = a;
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * t) % p;
            }
            t = (t * t) % p;
            b >>= 1;
        }
        cout << ans % p << endl;
    }
    return 0;
}
