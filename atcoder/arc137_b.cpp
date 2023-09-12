// https://atcoder.jp/contests/arc137/submissions/45491149
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define MAX_SIZE 300005
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
// types
typedef long long ll;
typedef unsigned long long ull;

int n;
int a[MAX_SIZE];
int assum[MAX_SIZE];
int main(int argc, char *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 就是计算子数组中哪个 `0个数-1个数` 最大，哪个最小

    int small = INT_MAX, big = -1;
    int buttom = 0, top = 0; // 之前的最小最大值
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            assum[i + 1] = assum[i] - 1;
        } else {
            assum[i + 1] = assum[i] + 1;
        }
        buttom = min(assum[i + 1], buttom);
        top = max(assum[i + 1], top);

        small = min(small, assum[i + 1] - top);
        big = max(big, assum[i + 1] - buttom);

        cerr << small << "\t" << big << endl;
    }
    for (int i = 0; i < n; ++i) {
        cerr << assum[i + 1] << " ";
    }
    cerr << endl;
    cout << big - small + 1 << endl;

    return 0;
}
