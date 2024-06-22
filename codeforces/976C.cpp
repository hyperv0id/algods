#include <bits/stdc++.h>
using namespace std;

struct _interval
{
    int l, r, i;
} itv[300005];

// https://codeforces.com/problemset/submission/976/266840918
void solve(int n)
{
    auto cmp = [&](const _interval &a, const _interval &b)
    {
        // 先按照左端点进行排序
        if (a.l != b.l)
            return a.l < b.l;
        // 如果左端点相同，则按照右端点从大到小排序
        return a.r > b.r;
    };
    std::sort(itv, itv + n, cmp);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << itv[i].l << " " << itv[i].r << " " << itv[i].i << endl;
    // }

    int mr = 0, mi = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (itv[i].r <= mr)
        {
            cout << itv[i].i + 1 << "\t" << mi + 1 << endl;
            return;
        }
        else
        {
            mr = itv[i].r;
            mi = itv[i].i;
        }
    }
    cout << -1 << "\t" << -1 << endl;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> itv[i].l >> itv[i].r;
        itv[i].i = i;
    }
    solve(t);

    return 0;
}