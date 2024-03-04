#include <bits/stdc++.h>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

// https://codeforces.com/problemset/submission/1352/249563639
ll foo(ll n, ll k) {
    // 每次循环有 n-1 个
    // 一共 k / n-1 个循环
    // 还差 k % (n-1) 个没有考虑
    // 3 7 ==> 1,2,4,5,7,8,10 == 3*3 + 7%3
    ll times = k / (n - 1);
    if (k % (n - 1) == 0) {
        // 4 12 ==> 123,567,91011,131415,
        return times * n - 1;
    }
    return times * n + k % (n - 1);
}

int n, k;
int main(int argc, char *argv[]) {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        cout << foo(n, k) << endl;
    }
    return 0;
}
