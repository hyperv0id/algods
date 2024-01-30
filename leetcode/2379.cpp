#include <bits/stdc++.h>

using namespace std;

// 2379. 得到 K 个黑块的最少涂色次数
// https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/
// https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/submissions/499363868
class Solution {
  public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0, ret = INT_MAX;
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'B')
                cnt++;
        }
        ret = cnt;
        for (int i = k; i < blocks.size(); ++i) {
            if (blocks[i] == 'B')
                cnt++;
            if (blocks[i - k] == 'B')
                cnt--;
            ret = max(ret, cnt);
        }
        return k - ret;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
