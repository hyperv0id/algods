#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-1; i>=0; i--){
            for(int j=nums.size()-1; j>i;j--){
                if(nums[j] > nums[i]){
                    swap(nums[j], nums[i]);
                    reverse(nums.begin()+i+1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

int main (int argc, char *argv[]) {
  int n;cin>>n;
  vector<int> nums(n);
  while(n--)cin>>nums[n];
  reverse(nums.begin(), nums.end());
  Solution().nextPermutation(nums);
  for(auto num:nums)cout << num<<" ";
  return 0;
}
