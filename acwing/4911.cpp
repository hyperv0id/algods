// https://www.acwing.com/problem/content/submission/code_detail/27473715/
#include <bits/stdc++.h>
using namespace std;
long long n, t, d, b;
int main() {
    cin >> n >> t;

    long long res = 0, end = 0;

    while (n--) {
        cin >> d >> b;

        if (end >= d)
            d = end + 1;

        end = d + b - 1;
        res += b;
        if (end >= t) {
            res -= end - t;
            break;
        }
    }

    cout << res << endl;
    return 0;
}
