#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/434875466/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, l = 0, r = 0, sum = 0;
        while(r<nums.size()){
            if(sum < target){sum+=nums[r++];}
            else{
                ans = min(ans, r-l);
                // cout << l << "\t" << r << "\t" << ans << endl;
                sum -= nums[l++];
            }
        }
        while(sum >= target){
            ans = min(ans, r-l);
            sum -= nums[l++];
        }
        return ans == INT_MAX ? 0 : ans;

    }
};
int main (int argc, char *argv[]) {
    
    return 0;
}
