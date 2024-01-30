
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/subarray-product-less-than-k/submissions/434879136/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0){return 0;}
        int ans = 0, l = 0, r = 0;
        long long mul = 1;
        for(r=0;r<nums.size();r++){
            mul *= nums[r];
            while(l <= r && mul >= k){ // 特殊案例: 1 1 1 1
                mul /= nums[l++];
            }
            ans += r-l + 1; // 以r为右端点的自数组的个数
        }
        return ans;
    }

};
int main (int argc, char *argv[]) {
    
    return 0;
}
