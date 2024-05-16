#include <bits/stdc++.h>
#include <iterator>

using namespace std;

// 275. H 指数 II
// https://leetcode.cn/problems/h-index-ii/
// https://leetcode.cn/problems/h-index-ii/submissions/501543742
class Solution {
  public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int l = 0, r = n - 1, m;
        while (l <= r) {
            m = l + r >> 1;
            bool isH = citations[m] < (n - m);
            if (isH)
                l = m + 1;
            else
                r = m - 1;
        }
        return n - l;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
