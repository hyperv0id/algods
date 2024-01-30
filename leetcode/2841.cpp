#include <bits/stdc++.h>

using namespace std;

// 2841. 几乎唯一子数组的最大和
// https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/description/
// https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/submissions/499374260/
class Solution {
  public:
    long long maxSum(vector<int> &nums, int m, int k) {
        unordered_map<long long, int> table;
        for (long long i = 0; i < k; ++i) {
            table[nums[i]]++;
        }
        auto calc_sum = [&table, m]() {
            if (table.size() < m)
                return (long long)0;
            long long ret = 0;
            for (auto &p : table)
                ret += p.first * p.second;
            return ret;
        };
        long long ans = calc_sum();
        for (int i = k, j = 0; i < nums.size(); ++i, ++j) {
            table[nums[i]]++;
            table[nums[j]]--;
            if (table[nums[j]] == 0)
                table.erase(nums[j]);
            ans = max(ans, calc_sum());
        }
        return ans;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
