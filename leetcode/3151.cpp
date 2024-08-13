#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/special-array-i/submissions/554991496
class Solution {
public:
  bool isArraySpecial(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
      if ((nums[i] & 1) == (nums[i - 1] & 1))
        return false;
    }
    return true;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
