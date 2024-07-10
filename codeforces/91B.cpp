#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];
int i;
int n;

inline void bs(int l, int r) {

    if (l == r) {
        cout << l - i - 1 << " ";
        return;
    }
    int mid = (l + r) >> 1;

    if (b[mid + 1] < a[i])
        bs(mid + 1, r);
    else
        bs(l, mid);
}

// https://codeforces.com/problemset/submission/91/256588745
int main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    b[n] = a[n];
    for (i = n - 1; i; i--) {
        b[i] = min(b[i + 1], a[i]);
    }
    for (i = 1; i < n; i++) {
        if (b[i + 1] >= a[i])
            cout << "-1 ";
        else
            bs(i + 1, n);
    }
    cout << "-1" << endl;
    return 0;
}
