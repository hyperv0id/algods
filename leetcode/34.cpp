#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/546327457
// 34. 在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int left = lower(nums, target, true);
    int right = lower(nums, target, false) - 1;

    if (left <= right && right < nums.size() && nums[left] == target &&
        nums[right] == target) {
      return vector<int>{left, right};
    }
    return vector<int>{-1, -1};
  }

  int lower(vector<int> &nums, int target, bool lower) {
    int l = 0, r = nums.size() - 1, m, ans = nums.size();
    while (l <= r) {
      m = l + r >> 1;
      if (nums[m] > target || (lower && nums[m] >= target)) {
        r = m - 1;
        ans = m;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
