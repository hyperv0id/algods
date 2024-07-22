#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/minimum-number-game/submissions/546048073
class Solution {
public:
  vector<int> numberGame(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
      std::swap(nums[i], nums[i + 1]);
    }
    return nums;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
