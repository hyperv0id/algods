# 代码长度: 323B    使用语言: Python    运行时间: 76ms    消耗内存: 35260KB

# 线性筛

N = int(input())

isPrime = [True] * (N+1)

for i in range(2, N):
    if i *i > N:break
    # 粗筛
    if not isPrime[i]:continue
    j = i + i
    while j <= N:
        isPrime[j] = False
        j+=i
    pass

for i in range(2, N):
    if isPrime[i]:
        print(i)
