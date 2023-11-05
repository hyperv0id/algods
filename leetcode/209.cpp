#include <bits/stdc++.h>
using namespace std;
/* 209. 长度最小的子数组
   给定一个含有 n 个正整数的数组和一个正整数 target
   。找出该数组中满足其总和大于等于 target 的长度最小的
   连续子数组 [numsl,numsl+1,..., numsr-1, numsr]
   ，并返回其长度。如果不存在符合条件的子数组，�回 0 。
*/

// https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/434875466
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int ans = INT_MAX, l = 0, r = 0, sum = 0;
        while (r < nums.size()) {
            if (sum < target) {
                sum += nums[r++];
            } else {
                ans = min(ans, r - l);
                // cout << l << "\t" << r << "\t" << ans << endl;
                sum -= nums[l++];
            }
        }
        while (sum >= target) {
            ans = min(ans, r - l);
            sum -= nums[l++];
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
