#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

// https://codeforces.com/problemset/submission/845/250310430
int main(int argc, char *argv[]) {
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        int n, a, b;
        cin >> n;
        vector<pair<int, int>> itv;
        while (n--) {
            cin >> a >> b;
            itv.push_back(make_pair(a, b));
        }
        std::sort(itv.begin(), itv.end(),
                  [](pair<int, int> &a, pair<int, int> &b) {
                      return a.first < b.first;
                  });
        int l = -1, r = -1;
        for (auto &p : itv) {
            if (p.first <= l && p.first <= r) {
                cout << "NO" << endl;
                return 0;
            }
            if (p.first > l)
                l = p.second;
            else if (p.first > r)
                r = p.second;
        }
        cout << "YES" << endl;
    }
    return 0;
}
