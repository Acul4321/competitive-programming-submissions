S = str(input())
first = -1
for i in range(len(S)):
    if S[i] == "|" and first == -1:
        first = i
    elif S [i] == "|" and first >= 0:
        second = i
print(S[0:first]+S[second+1:len(S)])