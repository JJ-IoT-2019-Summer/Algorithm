<<<<<<< HEAD
N = int(input())
arr = list(map(int,input().split()))

d=[0]*1000

d[0]=arr[0]

#DP 진행(바텀업)
d[1] = max(arr[0],arr[1])

for i in range(2,N):
    d[i] = max(d[i-1],d[i-2]+arr[i])

=======
N = int(input())
arr = list(map(int,input().split()))

d=[0]*1000

d[0]=arr[0]

#DP 진행(바텀업)
d[1] = max(arr[0],arr[1])

for i in range(2,N):
    d[i] = max(d[i-1],d[i-2]+arr[i])

>>>>>>> 65f2ee7131e2912c03d2122a15fcc235b3105750
print(d[N-1])