#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/3sum/submissions/542493724?envType=study-plan-v2&envId=top-100-liked
// 三数之和
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    auto _sum = [&nums](int idx) {
      return nums[idx] + nums[idx + 1] + nums[idx + 2];
    };
    for (int i = 0; i < n - 2; ++i) {
      // duplicate
      if (i && nums[i] == nums[i - 1])
        continue;
      if (_sum(i) > 0)
        break;
      if (nums[i] + nums[n - 1] + nums[n - 2] < 0)
        continue;

      int j = i + 1, k = n - 1;
      while (j < k) {
        int s = nums[i] + nums[j] + nums[k];
        if (s < 0)
          j++;
        else if (s > 0)
          k--;
        else {
          ans.push_back({nums[i], nums[j], nums[k]});

          for (++j; j < k && nums[j] == nums[j - 1]; ++j)
            ; // 跳过重复数字
          for (--k; k > j && nums[k] == nums[k + 1]; --k)
            ; // 跳过重复数字
        }
      }
    }
    return ans;
  }
};

int main (int argc, char *argv[]) {
    vector<int> input = {-1,0,1,2,-1,-4};
    Solution().threeSum(input);
    return 0;
}
