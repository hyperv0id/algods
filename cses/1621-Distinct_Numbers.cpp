// https://cses.fi/problemset/result/6970862/
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAX_SIZE 200005

int nums[MAX_SIZE];

int main(int argc, char *argv[]) {
    int n = 1, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    int i = 1;
    for (int j = 1; j < n; j++) {
        if (nums[j] != nums[j - 1]) {
            i++;
        }
    }
    cout << i;
    return 0;
}
