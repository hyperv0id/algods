#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/problemset/submission/1348/201619707
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr, vis(n + 1);
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (!vis[val]) {
            vis[val] = true;
            arr.push_back(val);
        }
    }
    if (arr.size() > k) {
        cout << "-1" << endl;
        return;
    }
    for (int i = arr.size(); i < k; i++) {
        arr.push_back(1);
    }
    cout << arr.size() * n << "\n";
    while (n--) {
        for (auto &&v : arr) {
            cout << v << " ";
        }
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
