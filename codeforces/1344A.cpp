#include <bits/stdc++.h>

using namespace std;
#define MAXSIZE 212345
int t, n;
int a[MAXSIZE];
bitset<MAXSIZE> b;

// https://codeforces.com/contest/1344/submission/202681892
int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        b.reset();
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b.set(((a[i] + i) % n + n) % n);
        }
        if (b.count() == n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
