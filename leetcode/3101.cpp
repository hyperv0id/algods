#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/count-alternating-subarrays/submissions/544396549
class Solution {
public:
  long long countAlternatingSubarrays(vector<int> &nums) {
    long long idx = 0;
    long long ans = 0;
    for (long long i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        long long diff = i - idx;
        ans += diff * (diff + 1) / 2;
        idx = i;
      }
    }
    long long diff = nums.size() - idx;
    ans += diff * (diff + 1) / 2;
    return ans;
  }
};
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Solution s;
  cout << s.countAlternatingSubarrays(arr) << endl;
  return 0;
}
