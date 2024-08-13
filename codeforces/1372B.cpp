#include <algorithm>
#include <bits/stdc++.h>

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

int a, b;
void OUT() { cout << a << " " << b<<endl;; }

// https://codeforces.com/problemset/submission/1372/271878145
// B. Omkar and Last Class of Math
void solve(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      a = n / i;
      b = n - a;
      OUT();
      return;
    }
  }
  cout << 1 << " " << n - 1 << endl;
}

int main(int argc, char *argv[]) {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    solve(n);
  }
  return 0;
}
