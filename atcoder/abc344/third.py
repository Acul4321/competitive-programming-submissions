A = [1,2,3]
N = len(A)
B = [2,4]
M = len(B)
C = [1,2,4,8,16,32]
L = len(C)
X = [1,5,10,50]
Q = len(X)

for x in X:
    able = False
    for a in A:
        for b in B:
            for c in C:
                if a+b+c == x:
                    able = True
    if able == True:
        print("yes")
    else:
        print("no")            
