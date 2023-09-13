#include <algorithm>
#include <array>
#include <bits/stdc++.h>
using namespace std;

// 189. 轮转数组
// 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
// https://leetcode.cn/problems/rotate-array/submissions/465725380/?envType=study-plan-v2&envId=top-interview-150
void reverse(int *begin, int *end) {
    while (begin < end) {
        *begin ^= *end;
        *end ^= *begin;
        *begin ^= *end;
        begin++;
        end--;
    }
}
void rotate(int *nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, nums + numsSize - 1);
    reverse(nums, nums + k - 1);
    reverse(nums + k, nums + numsSize - 1);
}

int main(int argc, char *argv[]) {
    int n, k;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    rotate(a, n, k);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
