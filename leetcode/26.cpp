#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int i = 1, j = 1;
        for (; j < nums.size();) {
            for (int iii = 0; iii < nums.size(); iii++) {
                cerr << nums[iii] << " ";
            }
            cerr << endl;
            if (nums[j] == nums[j - 1]) {
                j++;
            } else {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = s.removeDuplicates(arr);
    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
