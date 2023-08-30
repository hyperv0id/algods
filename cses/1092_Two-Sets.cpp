// https://cses.fi/problemset/result/6942324/
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
string to_upper(string a) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
// types
typedef long long ll;
typedef unsigned long long ull;

void solve(ll n) {
    int nn = n;
    ll target = n * (n + 1) >> 1;
    if (target & 1) {
        no();
        return;
    }
    target >>= 1;
    yes();
    unordered_set<int> table;
    while (target > 0) {
        // cerr << target << "\t" << n << endl;
        if (n <= target) {
            target -= n;
            table.insert(n);
            n--;
        } else {
            table.insert(target);
            target = 0;
        }
    }
    n = nn;
    cout << table.size() << endl;
    for (int i = 1; i <= n; i++) {
        if (table.find(i) != table.end()) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << n - table.size() << endl;
    for (int i = 1; i <= n; i++) {
        if (table.find(i) == table.end()) {
            cout << i << " ";
        }
    }
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    solve(n);
    return 0;
}
