// 41. 缺失的第一个正数
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        nums.push_back(0);
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            while (num >= 0 && num < n && nums[num] != num) {
                int old = nums[num];
                nums[num] = num;
                num = old;
            }
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
