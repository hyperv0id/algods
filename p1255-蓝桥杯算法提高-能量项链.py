
ans = 0

n = int(input())
arr = list(map(int, input().split()))

mval = max(arr)
midx = arr.index(mval)

cp = midx + 1
while cp != midx:
    if cp >= n:
        cp = 0
    ans += mval * arr[cp %n] * arr[(cp+1) % n]
    # print("{} * {} * {}".format(mval, arr[cp%n], arr[(cp+1)%n]))
    cp += 1

print(ans)