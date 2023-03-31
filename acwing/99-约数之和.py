#! /usr/bin/python3

# 2^3 --> 1 2 4 8
# 2^3 --> 2^3
# 6^3 --> 2^3 * 3^3

MOD = 9901
A, B = map(int, input().split())
# 对 A 分解质因数
def div(num:int):
    ans = []
    for i in range(2, num):
        if i >= num:break
        while num % i == 0:
            num //= i
            ans.append(i)
    return ans

# 求所有 质因子的组合的乘积 的和
        