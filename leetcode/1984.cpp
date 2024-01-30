#include <bits/stdc++.h>

using namespace std;

// 1984. 学生分数的最小差值
// https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
// https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores/submissions/499319432
class Solution {
  public:
    int minimumDifference(vector<int> &nums, int k) {
        k--;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = k; i < nums.size(); ++i) {
            ans = min(ans, nums[i] - nums[i - k]);
        }
        return ans;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
