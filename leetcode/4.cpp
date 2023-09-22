#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <vector>
// 寻找有序数组的中位数
// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和
// nums2。请你找出并返回这两个正序数组的 中位数 。
// 算法的时间复杂度应该为 O(log(m + n)) 。 using namespace std;
using namespace std;
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int total = nums1.size() + nums2.size();
        int m1 = (total + 1) / 2, m2 = total / 2 + 1;
        double r1 = lowestK(nums1, nums2, m1);
        // cerr << "_____________" << endl;
        double r2 = lowestK(nums1, nums2, m2);
        // cerr << "_____________" << endl;
        // cerr << r1 << "\t" << r2 << endl;
        return (r1 + r2) / 2;
    }
    double lowestK(vector<int> &nums1, vector<int> &nums2, int k, int i = 0,
                   int j = 0) {
        // cerr << k << " " << i << " " << j << endl;
        // 特殊情况
        if (i >= nums1.size()) {
            return nums2[j + k - 1];
        }
        if (j >= nums2.size()) {
            return nums1[i + k - 1];
        }
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        // 寻找各自的中位数
        int np1 = i + k / 2 - 1; // i是第一个, 因此要-1
        int np2 = j + k / 2 - 1;
        int v1 = np1 < nums1.size() ? nums1[np1] : INT_MAX;
        int v2 = np2 < nums2.size() ? nums2[np2] : INT_MAX;
        // cerr << ">" << v1 << " " << v2 << endl;
        // 删除 k/2 个数字，递归
        if (v1 < v2) {
            return lowestK(nums1, nums2, k - k / 2, i + k / 2, j);
        } else {
            return lowestK(nums1, nums2, k - k / 2, i, j + k / 2);
        }
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    int m, n;
    cin >> m >> n;
    vector<int> n1(m), n2(n);
    for (int i = 0; i < m; i++) {
        cin >> n1[i];
        cerr << n1[i] << " ";
    }
    cerr << endl;
    for (int i = 0; i < n; i++) {
        cin >> n2[i];
        cerr << n2[i] << " ";
    }
    cerr << endl;
    cout << s.findMedianSortedArrays(n1, n2);
    return 0;
}
