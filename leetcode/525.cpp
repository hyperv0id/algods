#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            cout << sum << endl;

            // 找到了之前的 -sum
            if (mp.count(sum)) {
                ans = max(ans, i - mp[sum]);
            }
            // 只记录最小的
            if (!mp.count(sum)) {
                mp[sum] = i;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
