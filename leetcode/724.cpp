class Solution {
  public:
    int pivotIndex(vector<int> &nums) {
        long l = 0, r = 0;
        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            r = sum - l - nums[i];
            if (l == r) {
                return i;
            }
            l += nums[i];
        }
        return -1;
    }
};
