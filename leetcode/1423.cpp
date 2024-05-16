#include <bits/stdc++.h>
#include <numeric>
#include <vector>

using namespace std;

// 1423. 可获得的最大点数
// https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/description/
// https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/submissions/500094646
class Solution {
  public:
    int maxScore(vector<int> &A, int k) {
        int ans = 0, total = 0;
        for (int i = A.size() - k; i < A.size(); ++i)
            total += A[i];
        ans = total;
        for (int l = A.size() - k, r = 0; l < A.size(); ++l, ++r) {
            total = total - A[l] + A[r];
            ans = max(ans, total);
        }
        return ans;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> vec = {1, 2, 3, 4, 5, 6, 1};
        cout << s.maxScore(vec, 3) << endl;
    }
    return 0;
}
