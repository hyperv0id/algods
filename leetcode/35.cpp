#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/search-insert-position/submissions/546330091
// 35. 搜索插入位置
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int idx = 0;
    // int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int l = 0, r = nums.size() - 1, m;
    // 第一个大于的。
    while (l <= r) {
      m = (r + l) >> 1;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return l;
  }
};
