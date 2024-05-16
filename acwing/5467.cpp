#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
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
        int n;
        scanf("%d", &n);
        long long ans = 0;
        int tmp;
        while (n--) {
            scanf("%d", &tmp);
            ans += tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}
