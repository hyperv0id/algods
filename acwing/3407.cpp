// https://www.acwing.com/problem/content/3407/
// 3404. 谁是你的潜在朋友 18 ms

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10005

int arr[MAX_N];
int main(int argc, char *argv[]) {
    int n, m, cnt;
    cin >> n >> m;

    unordered_map<int, int> table;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        table[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cnt = table[arr[i]];
        // cerr << arr[i] << endl;
        if (cnt > 1) {
            cout << cnt - 1 << endl;
        } else {
            cout << "BeiJu" << endl;
        }
    }

    return 0;
}
