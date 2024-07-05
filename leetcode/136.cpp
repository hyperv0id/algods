#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/single-number/submissions/544176816?envType=study-plan-v2&envId=top-100-liked
// 136. 只出现一次的数字

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int val = 0;
    for (auto num : nums) {
      val ^= num;
    }
    return val;
  }
};
