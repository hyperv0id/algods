#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    uint64_t n, k;
    cin >> n >> k;
    if (k > n || __builtin_popcount(n) > k) {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> arr(k, 1);
    n -= k;
    for (int i = 0; i < arr.size() && n > 0; i++) {
        for (; arr[i] <= n; arr[i] <<= 1) {
            n -= arr[i];
        }
    }
    cout << "YES" << endl;
    for (auto a : arr) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
