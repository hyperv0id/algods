#include <bits/stdc++.h>
#include <climits>
#include <deque>

using namespace std;

// https://leetcode.cn/problems/sliding-window-maximum/submissions/543299705?envType=study-plan-v2&envId=top-100-liked
// 滑动窗口最大值
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> q; // 单调递减
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      while (!q.empty() && nums[q.back()] <= nums[i]) {
        // 我现在的值更大
        q.pop_back(); // 
      }
      q.push_back(i);
      if (i - q.front() >= k)
        q.pop_front();
      if (i >= k - 1)
        ans.push_back(nums[q.front()]);
    }
    return ans;
  }
};
