#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

int n, k;
ll x;
// https://codeforces.com/problemset/submission/1742/249470520
void foo() {
    cin >> n >> k;
    vector<ll> acc, mh;
    acc.push_back(0);
    mh.push_back(0);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        acc.push_back(acc.back() + x);
        mh.push_back(max(mh.back(), x));
    }
    for (int i = 0; i <= n; ++i)
        cerr << mh[i] << " ";
    cerr << endl;
    for (int i = 0; i <= n; ++i)
        cerr << acc[i] << " ";
    cerr << endl;
    while (k--) {
        cin >> x;
        int pos = upper_bound(mh.begin(), mh.end(), x) -
                  mh.begin(); // 第一个大于x的位置
        cout << acc[pos - 1] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        foo();
    }
    return 0;
}
