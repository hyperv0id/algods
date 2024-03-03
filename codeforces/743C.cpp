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

int main(int argc, char *argv[]) {
    int tc = 1;
    // cin>>tc;
    while (tc--) {
        int n, x, y, z, subs;
        cin >> n;
        if (n <= 1)
            printf("-1");
        else
            printf("%d %d %d\n", n, n + 1, n * (n + 1));
    }
    return 0;
}
