#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/two-sum/submissions/542482334?envType=study-plan-v2&envId=top-100-liked
// 两数之和
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> table; // num, index
    for (int i = 0; i < nums.size(); ++i) {
      table[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
      int f = table[target - nums[i]];
      if (f && f != i)
        return {min(f, i), max(f, i)};
    }
    return {};
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
