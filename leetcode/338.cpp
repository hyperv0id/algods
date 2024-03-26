#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n;) {
            int j = i, i2 = i << 1;
            while (j < i2 && j <= n) {
                ans[j] += ans[j - i] + 1;
                j++;
            }
            i = i2;
        }
        return ans;
    }
};
int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    Solution s;
    for (auto i : s.countBits(n)) {
        cout << i << " ";
    }
    return 0;
}
