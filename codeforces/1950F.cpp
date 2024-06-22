#include <iostream>
#include <math.h>
using namespace std;

// https://codeforces.com/problemset/submission/1950/266836988
int solve(int a, int b, int c)
{
    // 不存在这种树
    if (a * 2 + b + 1 != a + b + c)
        return -1;
    if (a == 0)
        return b;
    // 处理所有的a需要
    int ah = 0;
    while (((1 << ah) - 1) < a)
        ah++;
    int r1 = (1 << ah) - 1 - a;
    int r2 = 2 * (1 + a - (1 << (ah - 1)));
    int remain = a + b + c - 2 * a - 1;
    if (remain <= r1)
        return ah;
    remain -= r1;
    return ah + remain / (r1 + r2) + (remain % (r1 + r2) != 0 ? 1 : 0);
    // cout << ah << "\t" << r1 << "\t" << r2 << endl;
    // return 0;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
    return 0;
}