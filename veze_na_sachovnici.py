n = int(input())
board = []
for _ in range(n):
    line = [char for char in input()]
    board.append([])
    for i, char in enumerate(line):
        if char != "X":
            board[_].append(i)

def find_perm(so_far, i):
    if i == n:
        return 1
    s = 0
    for element in board[i]:
        if element in so_far:
            pass
        else:
            new = so_far | {element}
            s += find_perm(new, i + 1)
    return s
        
ans = find_perm(set(), 0)

print(ans)