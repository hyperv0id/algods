#include <bits/stdc++.h>
#include <iomanip>
#include <iostream>
using namespace std;

// https://leetcode.cn/problems/max-points-on-a-line/submissions/462968055/?envType=study-plan-v2&envId=top-interview-150
#define MAX_BIT 16
typedef long long ll;

class Solution {
  public:
    int maxPoints(vector<vector<int>> &points) {
        if (points.size() <= 2) {
            return points.size();
        }
        // 两点确定一条直线
        unordered_map<long long, int> table;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                table[get_line(points[i][0], points[i][1], points[j][0],
                               points[j][1])]++;
            }
        }
        auto elem = max_element(table.begin(), table.end(),
                                [](const std::pair<long long, int> &a,
                                   const std::pair<long long, int> &b) -> bool {
                                    return a.second < b.second;
                                });
        long long key = elem->first;

        // cerr << (short)(key >> (2 * MAX_BIT)) << " "
        //      << (short)((key >> MAX_BIT)) << " " << (short)(key) << endl;
        int sum = elem->second;
        int ans = 1;
        while (sum > 0) {
            sum -= ans++;
        }
        return ans;
    }

    long long get_line(int x1, int y1, int x2, int y2) {
        short a, b, c; // A*x + B*y + c=0;
        // 特判斜率为0或正无穷
        if (x1 == x2) {
            a = 1;
            b = 0;
        } else if (y1 == y2) {
            a = 0;
            b = 1;
        } else {
            a = y2 - y1;
            b = x1 - x2;
            // 化简
            if (a * b != 0) {
                int g = gcd(abs(a), abs(b));
                a /= g;
                b /= g;
            }
        }
        c = 0 - a * x1 - b * y1;
        // 统一符号
        if (a < 0) {
            a = -a;
            b = -b;
            c = -c;
        } // 保证key是一个正数
        a = (unsigned)a;
        b = (unsigned)b;
        c = (unsigned)c;
        // fprintf(stderr, "(%d,%d),(%d,%d)=>%d %d %d\n", x1, y1, x2, y2, a, b,
        // c);
        return ((ll)a << (2 * MAX_BIT)) + ((ll)b << MAX_BIT) + c;
    }
};

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    Solution s;
    cout << s.maxPoints(arr) << endl;
    return 0;
}
