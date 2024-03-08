#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 200005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

int last1(int x) {
    int ans = 0;
    while (!(x & 1)) {
        x >>= 1;
        ans++;
    }
    return ans;
}

int f1arr[MAX_SIZE];

// https://codeforces.com/problemset/submission/1744/249568254
int foo() {
    int n, x;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cnt += last1(x);
    }
    // 1. 计算缺多少
    if (cnt >= n) {
        return 0;
    }
    // 2. 补上
    vector<int> f1clone = vector<int>(f1arr, f1arr + n);
    // 从大小排序
    sort(f1clone.begin(), f1clone.end(), std::greater<int>());
    for (int i = 0; i < n; ++i) {
        cnt += f1clone[i];
        if (cnt >= n) {
            return i + 1;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i <= MAX_SIZE; ++i)
        f1arr[i - 1] = last1(i);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        cout << foo() << endl;
    }
    return 0;
}
