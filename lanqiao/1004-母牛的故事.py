# 代码长度: 403B    使用语言: Python    运行时间: 79ms    消耗内存: 35260KB

arr = [[],[0,0,0,1]]

n = -1

while True:
    n = int(input())
    if n == 0:break
    while n >= len(arr):
        last = arr[-1].copy()
        last[-1] += last[-2] #  大于 4 岁的
        last[1:3] = last[0:2] # 老的
        last[0] = last[-1] # 今年新出生的
        arr.append(last)
    
    print(sum(arr[n]))
    
    pass
    