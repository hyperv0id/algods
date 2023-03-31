#! /bin/python3

# https://www.acwing.com/problem/content/1240/

# 日志条数, 时间段, K个赞
N, D, K = map(int, input().split())

table = dict()

for _ in range(N):
    log_ts, log_id = map(int, input().split())
    if log_id not in table:
        table[log_id] = [log_ts]
    else:
        table[log_id].append(log_ts)

# 开始统计
ans = []
for key, varr in table.items():
    varr.sort()
    # print(key, "\t", " ".join(map(str, varr)))
    # 招待长度为 K 的数组, 最大值和最小值相差小于 D
    i, j = 0, K-1
    while j < len(varr):
        if varr[j] - varr[i] < D:
            # print(key, "-->", varr[i], varr[j])
            ans.append(key)
            break
        i += 1
        j += 1
ans.sort()
print("\n".join(map(str, ans)))