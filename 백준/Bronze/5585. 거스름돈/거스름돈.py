N = int(input())
remain = 1000-N

coins = [500,100,50,10,5,1]

cnt = 0
for coin in coins:
    if remain >= coin:
        cnt += remain // coin
        remain = remain % coin
print(cnt)
