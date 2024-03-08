#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
#define _rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

void yes() { printf("Yes\n"); }
void no() { printf("No\n"); }

// https://codeforces.com/problemset/submission/1542/250236384
bool foo(ll n, ll a, ll b) {
    if (b == 1) {
        return 1;
    }
    if (a == 1) {
        return n % b == 1;
    }
    // 找到最小的 m 使得 m%b == n % b
    // m 需要是 long long,乘法会溢出
    ll m = 1;
    while (m <= n) {
        if (m % b == n % b) {
            return 1;
        }
        m *= a;
    }
    return false;
}

int main(int argc, char *argv[]) {
    ll tc = 1;
    cin >> tc;
    while (tc--) {
        ll n, a, b;
        cin >> n >> a >> b;
        if (foo(n, a, b)) {
            yes();
        } else {
            no();
        }
    }
    return 0;
}
