#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long *a = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += a[i] * (i + 1) * (n - i);
    }
    cout << ans << endl;
    return 0;
}
