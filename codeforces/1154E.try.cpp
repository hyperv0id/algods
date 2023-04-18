#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> pos;
int main(int argc, char *argv[]) {
    cin >> n >> k;
    pos = vector<int>(n + 1);
    vector<int> rawInput(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> rawInput[i];
        pos[rawInput[i]] = i;
    }

    vector<int> left(n), right(n); // 每个数字左边元素和右边元素
    for (int i = 0; i < n; i++) {
    }
    vector<int> output(n, -1);

    return 0;
}
