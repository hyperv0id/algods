#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <functional>
#include <vector>

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
        vector<int> arr(n + 1);
        arr[0] = INT_MAX;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);
        int small = *min_element(arr.begin(), arr.end());
        int sub = small - (small % n);
        for (int i = 1; i <= n; ++i)
            arr[i] -= sub;
        auto solve = [&arr, n]() {
            for (int i = 1; i <= n; ++i) {
                if (arr[i] < i)
                    return i;
            }
            for (int i = 1; i <= n; ++i) {
                if (arr[i] < i + n)
                    return i;
            }
            return -1;
        };

        printf("%d\n", solve());
    }
    return 0;
}
