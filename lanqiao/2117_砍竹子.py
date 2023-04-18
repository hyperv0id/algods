import os
import math
import sys

# 请在此输入您的代码
N = int(input())
arr = list(map(int, input().split()))

def sqrtl(num:int):
#    print("sq", n, "=", int(math.sqrt(1 + (num>>1))))
    return int(math.sqrt(1 + (num>>1)))

    
kan = []
ans = 0
for n in arr:
    kan_i = [1]
    while n>1:
        kan_i.append(n)
        n = sqrtl(n)
        ans += 1
    kan.append(kan_i)
    
# print(kan, ans)

for i in range(1, N):
    ans += 1
    for last in kan[i-1]:
        if last in kan[i]:
            ans -= 1

print(ans)






# **连续的**一段 假设错误
# tab = set()
# tab.add(1)
# ans = 0
# for i, n in enumerate(arr):
#     while n>1:
#         tab.add(n)
#         n = sqrtl(n)
# 
# print(len(tab))