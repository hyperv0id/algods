#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<string> &words) {
        vector<int> wi;
        for (auto &&s : words) {
            int n = 0;
            for (char c : s) {
                n |= 1 << (c - 'a');
            }
            wi.push_back(n);
        }
        int ans = 0;
        for (int i = 0; i < wi.size(); ++i) {
            for (int j = 0; j < i; j++) {
                if (wi[i] & wi[j])
                    continue;
                int mul = words[i].size() * words[j].size();
                ans = max(ans, mul);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
