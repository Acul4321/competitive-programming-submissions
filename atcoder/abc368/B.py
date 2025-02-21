N = 3
A = list(map(int, input().split()))
L = 0

while min(A) >= 0:
    A.sort(reverse=True)
    A[0] -=1
    A[1] -=1
    L +=1
L -=1
print(L)
