n = int(input())

if n == 1 or n == 3:
	print(-1)
else:
    cnt = 0

    cnt += n // 5
    n %= 5

    if n % 2:
        n += 5
        print(n // 2 + cnt - 1)
    else:
        print(cnt + n // 2)