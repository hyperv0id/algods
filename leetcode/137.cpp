class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        vector<int> bc(32);
        for (auto n : nums) {
            for (int i = 0; i < 32; i++) {
                if ((n >> i) & 1) {
                    bc[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if (bc[i] % 3)
                ans |= 1 << i;
        }
        return ans;
    }
};
