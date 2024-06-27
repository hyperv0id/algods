#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/move-zeroes/description/?envType=study-plan-v2&envId=top-100-liked
// 移动零
// https://leetcode.cn/problems/move-zeroes/submissions/303639234?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[j++] = nums[i];
            }
        }
        while(j<nums.size()){
            nums[j++] = 0;
        }
    }
};

int main(int argc, char *argv[]) {
  Solution s;
  return 0;
}
