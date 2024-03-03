#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define endl '\n'
#define MAX_SIZE 100005
#define MOD 1000000007
// types
typedef long long ll;
typedef unsigned long long ull;

// https://codeforces.com/contest/1520/submission/249465361
int main(int argc, char *argv[]) {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n, t;
        long long ans = 0;
        cin >> n;
        int *arr = new int[n];
        unordered_map<int, int> table;
        for (int i = 0; i < n; ++i) {
            cin >> t;
            int diff = t - i;
            ans += table[diff];
            table[diff]++;
        }
        cout << ans << endl;
    }
    return 0;
}
