n = int(input())
cur = 0
while True:
    try:
        s_in = input()
        if cur < n:
            print(s_in, "\n")
        else:
            print("\n\n".join(s_in.split()))
        cur += 1
    except:
        break