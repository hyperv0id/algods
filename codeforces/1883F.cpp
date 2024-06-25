#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

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

unordered_map<int, int> idx;
int n;
int a[MAX_SIZE];
// 子序列而不是子数组
ll solve(int n) {
  // 数字出现的右端点
  ll ans = 0;
  int rem = idx.size(); // 有多少种数字可用
  if (rem == n) {
    ll ans = n;
    ans *= (n + 1);
    ans /= 2;
    return ans;
  }
  for (int i = 0; i < n; ++i) {
    if (idx[a[i]] > 0) {
      ans += rem; // 作为左端点
      idx[a[i]] *= -1;
    }
    if (abs(idx[a[i]]) == i + 1) {
      rem--; // 此数字无法使用了
    }
  }
  return ans;
}

// https://codeforces.com/problemset/submission/1883/267317912
// iostream卡了很久
int main(int argc, char *argv[]) {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    idx.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      idx[a[i]] = i + 1;
    }
    cout << solve(n) << endl;
  }
  return 0;
}
