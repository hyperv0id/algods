#include <algorithm>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    // https://codeforces.com/problemset/submission/1862/267812571
    auto solve = [&a, m, d]() {
      ll ans = 0;
      set<pair<int, int>> pos;
      ll sum = 0;
      for (int i = 0; i < a.size(); ++i) {
        ans = max(ans, sum + a[i] - d * static_cast<ll>(i + 1));
        if (a[i] > 0) {
          pos.insert({a[i], i});
          sum += a[i];
          if (pos.size() >= m) {
            sum -= pos.begin()->first;
            pos.erase(pos.begin());
          }
        }
      }
      return ans;
    };
    cout << solve() << endl;
  }
  return 0;
}
