#include <bits/stdc++.h>
#include <climits>

using namespace std;

// https://leetcode.cn/problems/WHnhjV/submissions/466430794/
class Solution {
  public:
    int giveGem(vector<int> &gem, vector<vector<int>> &operations) {
        for (auto &&op : operations) {
            int val = gem[op[0]] >> 1;
            gem[op[0]] -= val;
            gem[op[1]] += val;
        }
        int small = INT_MAX, big = -1;
        for (auto g : gem) {
            small = min(small, g);
            big = max(big, g);
        }
        return big - small;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
