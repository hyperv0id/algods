#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int r = count(nums.begin(), nums.end(), 0);
    int g = r + count(nums.begin(), nums.end(), 1);
    int b = g + count(nums.begin(), nums.end(), 2);
    int i = 0;
    while (i < r) {
      nums[i++] = 0;
    }
    while (i < g) {
      nums[i++] = 1;
    }
    while (i < b) {
      nums[i++] = 2;
    }
  }
};
