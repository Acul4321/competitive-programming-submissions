N, K = map(int, input().split())
A = list(map(int, input().split()))

B = A[N-K:]+ A[:N-K]

print(*B)