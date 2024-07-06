#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/find-the-duplicate-number/submissions/544398099?envType=study-plan-v2&envId=top-100-liked
// 287. 寻找重复数
class Solution {
public:
  // n+1个边，n个点，一定成环
  int findDuplicate(vector<int> &nums) {
    int now = nums.front();
    while(nums[now] > 0){
        int t = nums[now];
        nums[now] *= -1;
        now = t;
    }
    for(int&n:nums){n=abs(n);}
    return now;
  }
};


int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
