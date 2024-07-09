#include <bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/find-pivot-index/submissions/544937094
// 724. 寻找数组的中心下标

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    long l = 0, r = 0;
    long sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    for (int i = 0; i < nums.size(); i++) {
      r = sum - l - nums[i];
      if (l == r) {
        return i;
      }
      l += nums[i];
    }
    return -1;
  }
};
