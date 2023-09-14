#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/queens-that-can-attack-the-king/submissions/466254167/
class Solution {
  public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                            vector<int> &king) {
        vector<vector<int>> ans;

        unordered_set<long long> table;
        for (auto &&q : queens) {
            table.insert(((long long)q[0] << 32) + q[1]);
        }

        for (int dirx = -1; dirx < 2; dirx++) {
            for (int diry = -1; diry < 2; diry++) {
                if (dirx == 0 && diry == 0)
                    continue;
                long long posx = king[0], posy = king[1];
                while (isInBox(posx, posy, 8, 8)) {
                    if (table.find((posx << 32) + posy) != table.end()) {
                        ans.push_back({(int)posx, (int)posy});
                        break;
                    }
                    posx += dirx;
                    posy += diry;
                }
            }
        }

        return ans;
    }

    bool isInBox(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
