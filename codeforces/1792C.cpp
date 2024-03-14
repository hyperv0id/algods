#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

// https://codeforces.com/problemset/submission/1792/251214566
int foo(int n, vector<int> &arr) {
    auto is_sorted = [n, arr](int a) {
        if (n / 2 < a)
            return true;
        int l = a, r = n - a + 1;
        for (int i : arr) {
            if (i == l)
                l++;
            if (l > r)
                return true;
        }
        // fprintf(stderr, "%d-%d: %d&%d\n", a, n - a + 1, l, r);
        return l == r + 1;
    };
    int low = 1, high = 1 + n / 2, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (!is_sorted(mid)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low - 1;
}

int main(int argc, char *argv[]) {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        cout << foo(n, arr) << endl;
    }
    return 0;
}
