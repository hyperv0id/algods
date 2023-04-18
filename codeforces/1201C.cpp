#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/submission/1201/201624418
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    n -= n >> 1;
    a = vector<int>(a.begin() + n - 1, a.end()); // a 数组的上半部分

    int i;
    for (i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            continue;
        }
        if (a[i] - a[i - 1] > k / i)
            break;
        k -= i * (a[i] - a[i - 1]);
    }
    cout << (a[i - 1] + k / i) << endl;

    return 0;
}
