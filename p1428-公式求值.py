MOD = 999101
n = int(input())
m = int(input())
k = int(input())

def qmid(num, k):
    """快速幂 MOD
    """
    ans = 1
    while k:
        if k & 1:
            ans *= num
            ans %= MOD
        num *= num
        k >>= 1
    return ans

def jiec(num):
    ans = 1
    for i in range(num):
        ans *= i+1
        ans %= MOD
    return ans

ans = 0

# 计算 n-i 的阶层
ni_jiec = jiec(n)
n_jiec = ni_jiec
i_jiec = 1

# 0^any == 0
for i in range(1, n+1):
    mid = qmid(i, k)
    print("qmid {}, {} = {}".format(i, k, mid))
    i_jiec *= i
    ni_jiec //= i
    # i! * i^k // (n-i)!
    ans += n_jiec * mid // ni_jiec // i_jiec
ans *= n_jiec
ans //= jiec(m)
ans //= jiec(n-m)

print(ans)