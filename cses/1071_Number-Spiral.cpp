// https://cses.fi/problemset/result/6941945/
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

ll solve(int x, int y) {
    ll m = max(x, y);
    int posx, posy;
    if (m & 1) {
        posx = 1;
        posy = m;
    } else {
        posy = 1;
        posx = m;
    }
    ll diff = abs(posx - x) + abs(posy - y);
    return m * m - diff;
}

int main(int argc, char *argv[]) {
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        int n;
        cin >> n;
        while (n--) {
            int x, y;
            cin >> x >> y;
            cout << solve(x, y) << endl;
        }
    }
    return 0;
}
