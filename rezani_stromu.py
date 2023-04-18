import sys
sys.setrecursionlimit(10000)

n = int(input())
total_c = 0
adj = [[] for _ in range(n)]
costs = {}
for _ in range(n-1):
    u, v, c = list(map(int, input().split()))
    u -= 1
    v -= 1
    total_c += c
    adj[u].append(v)
    adj[v].append(u)
    costs[f"{u};{v}"] = c
    costs[f"{v};{u}"] = c

visited = [False for _ in range(n)]
ans = [float("inf"), [None, None]]
def dfs(parent, node):
    global ans
    if visited[node]: return 0
    visited[node] = True

    sm = 0
    for s in adj[node]:
        if not visited[s]: sm += costs[f"{node};{s}"]
        sm += dfs(node, s)

    if parent != None:
        my_sum = sm + costs[f"{node};{parent}"]
        if ans[0] > min(ans[0], max(sm, total_c - my_sum)):
            ans = [min(ans[0], max(sm, total_c - my_sum)), [node + 1, parent + 1]]
    return sm


dfs(None, 0)
print(ans[0])