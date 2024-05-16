#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// 2461. 长度为 K 子数组中的最大和
// https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
// https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/submissions/500087284
class Solution {
  public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        unordered_map<long long, int> table;
        long long total = 0, ans = 0;
        for (int i = 0; i < k; ++i) {
            total += nums[i];
            table[nums[i]]++;
        }
        if (table.size() == k)
            ans = total;
        for (int l = 0, r = k; r < nums.size(); ++r, l++) {
            total = total + nums[r] - nums[l];
            ++table[nums[r]];
            if (--table[nums[l]] == 0)
                table.erase(nums[l]);
            if (table.size() == k)
                ans = max(ans, total);
        }
        return ans;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> vec = {1, 5, 4, 2, 9, 9, 9};
        int ans = s.maximumSubarraySum(vec, 3);
        cout << ans << endl;
    }
    {
        vector<int> vec = {4, 4, 4};
        int ans = s.maximumSubarraySum(vec, 3);
        cout << ans << endl;
    }
    {
        vector<int> vec = {1, 1, 1, 7, 8, 9};
        int ans = s.maximumSubarraySum(vec, 3);
        cout << ans << endl;
    }
    {
        vector<int> vec = {1, 1, 1, 7, 8, 9};
        int ans = s.maximumSubarraySum(vec, 3);
        cout << ans << endl;
    }
    return 0;
}
