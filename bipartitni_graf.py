N = int(input())
M = int(input())
edges = [[] for _ in range(N)]
for i in range(M):
    a, b = list(map(int, input().split()))
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)

col = [-1] * N
def solve():

    q = []
   
    for i in range(N):
       
        if (col[i] == -1):
           
            q.append([i, 0])
            col[i] = 0
           
            while len(q) != 0:
                p = q[0]
                q.pop(0)
               
                v = p[0]
                 
                c = p[1]
                   
                for j in edges[v]:
                   
                    if (col[j] == c):
                        return False
                   
                    if (col[j] == -1):
                       
                        if c == 1:
                            col[j] = 0
                        else:
                            col[j] = 1
                        q.append([j, col[j]])

    return True

if solve():
    line1 = []
    line2 = []
    for i, v in enumerate(col):
        if v == 1:
            line1.append(i + 1)
        else:
            line2.append(i + 1)
    
    print(*line1)
    print(*line2)

else:
    print("Nelze")
