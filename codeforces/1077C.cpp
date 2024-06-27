#include <bits/stdc++.h>
#include <cstdint>
#include <cstdio>

using namespace std;
#define endl '\n'
#define MAX_SIZE 200005
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
// types
typedef long long ll;
typedef unsigned long long ull;

int a[MAX_SIZE];
// https://codeforces.com/problemset/submission/1077/267329262
void solve(int n) {
  vector<int> ans;
  // 删除a后有 x = sum-a>>1, sum-a为偶数
  ll sum = accumulate(a, a + n, (ll)0);
  unordered_map<ll, int> cnt; // 数字出现次数
  for (int i = 0; i < n; ++i) {
    cnt[a[i]]++;
  }
  // for (auto &&[k, v] : cnt)
    // cerr << k << " " << v << endl;
  for (int i = 0; i < n; ++i) {
    ll v = a[i];
    ll total = sum - v;
    if (total & 1)
      continue;
    total /= 2;
    // cerr << v << " " << total << " " << cnt[v] << endl;
    if (cnt[total]) {
      if (cnt[total] == 1 && (v == total))
        continue;
      ans.emplace_back(i + 1);
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i : ans)
    printf("%d ", i);
}
int main(int argc, char *argv[]) {
  int tc = 1;
  // cin>>tc;
  while (tc--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    solve(n);
  }
  return 0;
}
