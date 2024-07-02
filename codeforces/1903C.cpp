#include <bits/stdc++.h>
#include <climits>

using namespace std;
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
// types
typedef long long ll;
typedef unsigned long long ull;

// https://codeforces.com/problemset/submission/1903/268483901
int main(int argc, char *argv[]) {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int ans = INT_MIN;
    auto solve = [&]() {
      long long ans = 0;
      long long suff = 0;
      for (int i = n - 1; i >= 0; --i) {
        suff += a[i];
        if (i == 0 || suff > 0)
          ans += suff;
      }
      return ans;
    };
    cout << solve() << endl;
  }
  return 0;
}
