#include <bits/stdc++.h>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

// https://codeforces.com/problemset/submission/50/256596596
int main(int argc, char *argv[]) {
    int tc = 1;
    string s;
    cin >> s;
    ll a[256] = {0};
    // cin>>tc;
    while (tc--) {
        ll ans = 0;
        for (char c : s)
            a[c]++;
        for (char c : s)
            ans += a[c];
        cout << ans;
    }
    return 0;
}
