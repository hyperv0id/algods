#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/harshad-number/submissions/543699233
class Solution {
public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    auto hsd = [](int x) {
      int sum = 0;
      while (x) {
        sum += x % 10;
        x /= 10;
      }
      return sum;
    };
    int hs = hsd(x);
    if(x % hs == 0) return hs;
    return -1;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
