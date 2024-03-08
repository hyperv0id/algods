#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

// https://codeforces.com/problemset/submission/492/249569591
int main(int argc, char *argv[]) {
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        int n, l;
        cin >> n >> l;
        double *arr = new double[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        double gap = arr[0];
        for (int i = 1; i < n; ++i) {
            gap = max(gap, (arr[i] - arr[i - 1]) / 2);
        }
        gap = max(gap, l - arr[n - 1]);
        printf("%lf\n", gap);
    }
    return 0;
}
