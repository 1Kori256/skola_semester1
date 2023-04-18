mapa = []
try:
    while(riadok := input()):
        mapa.append([*riadok])
except Exception:
    pass

R = len(mapa)
S = len(mapa[0])

visited = [[0 for i in range(S)] for j in range(R)]

def isValid(row, col):
   
    if (row < 0 or col < 0 or row >= R or col >= S):
        return False
 
    if (visited[row][col] != 0):
        return False
    
    if (mapa[row][col] == "#"):
        return False

    return True

def bfs(x, y, total, sum_x, sum_y):
    
    visited[x][y] = 1
    total += 1
    sum_x += x
    sum_y += y
    if isValid(x + 1, y):
        t, x1, y1 = bfs(x + 1, y, 0, 0, 0)
        total += t
        sum_x += x1
        sum_y += y1
    if isValid(x - 1, y):
        t, x1, y1 = bfs(x - 1, y, 0, 0, 0)
        total += t
        sum_x += x1
        sum_y += y1
    if isValid(x, y + 1):
        t, x1, y1 = bfs(x, y + 1, 0, 0, 0)
        total += t
        sum_x += x1
        sum_y += y1
    if isValid(x, y - 1):
        t, x1, y1 = bfs(x, y - 1, 0, 0, 0)
        total += t
        sum_x += x1
        sum_y += y1

    return [total, sum_x, sum_y]

ans = []
for i in range(S):
    for j in range(R):
        if isValid(i, j):
            ans.append(bfs(i, j, 0, 0, 0))
ans.sort(reverse=True)
print(f"{ans[0][0]} {ans[0][1] // ans[0][0]} {ans[0][2] // ans[0][0]}")
        
