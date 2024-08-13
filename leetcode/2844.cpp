#include <bits/stdc++.h>

using namespace std;


// 2844. 生成特殊数字的最少操作
// https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/submissions/549547847?envType=daily-question&envId=2024-07-25
class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int f0 = false, f5 = false;
        for(int i=n-1; i>=0; i--) {
            if(num[i] == '0' || num[i] == '5') {
                if(f0) {
                    return n - i - 2;                
                }
                if(num[i] == '0') f0 = true;
                if(num[i] == '5') f5 = true;
            } else if(num[i] == '2' || num[i] == '7') {
                if(f5) return n-i-2;
            }
        }
        if(f0) return n-1;
        return n;
    }
};
