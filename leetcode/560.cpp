#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int ans = 0;
        vector<int> pre_sum(nums.size() + 1, 0);
        // 计算前缀和
        partial_sum(nums.begin(), nums.end(), pre_sum.begin() + 1);
        // 遍历
        unordered_map<int, int> table;
        for (int i = 0; i < pre_sum.size(); ++i) {
            ans += table[pre_sum[i] - k];
            table[pre_sum[i]]++;
        }

        return ans;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << s.subarraySum(arr, k);
    return 0;
}
