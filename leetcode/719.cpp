#include <bits/stdc++.h>
using namespace std;
/**
713. 乘积小于 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于
k 的连续子数组的数目。
  */
// https://leetcode.cn/problems/subarray-product-less-than-k/submissions/434879136
class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k == 0) {
            return 0;
        }
        int ans = 0, l = 0, r = 0;
        long long mul = 1;
        for (r = 0; r < nums.size(); r++) {
            mul *= nums[r];
            while (l <= r && mul >= k) {
                mul /= nums[l++];
            }
            ans += r - l + 1; // 以r为右端点的自数组的个数
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
