#include <bits/stdc++.h>
#include <numeric>

using namespace std;

// 643. 子数组最大平均数 I
// https://leetcode.cn/problems/maximum-average-subarray-i/description/
// https://leetcode.cn/problems/maximum-average-subarray-i/submissions/499320954/
class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        double sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        double ans = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i];
            sum -= nums[i - k];
            ans = max(ans, sum);
        }
        return ans / k;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
