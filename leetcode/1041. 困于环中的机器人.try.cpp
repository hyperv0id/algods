#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
  public:
    pair<int, int> getDir(int angle) {
        angle /= 180;
        angle *= M_PI;
        return make_pair(cos(angle), sin(angle));
    }
    bool isRobotBounded(string instrustions) {
        int front = 90;
        pair<int, int> pos(0, 0);
        for (auto &&c : instrustions) {
            if (c == 'G') {
                auto move = getDir(front);
                pos.first += move.first;
                pos.second += move.second;
            } else if (c == 'L') {
                front -= 90;
            } else {
                front += 90;
            }
        }
        return front == 90 && pos.first == 0 && pos.second == 0;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
