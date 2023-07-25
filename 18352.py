import sys
from collections import deque

input = sys.stdin.readline
n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n + 1)]

distance = [-1 for _ in range(n + 1)]
distance[x] = 0
for i in range(m):
    s, d = map(int, input().split())
    graph[s].append(d)


queue = deque([x])
while queue:
    v = queue.popleft()
    for adj_v in graph[v]:
        if distance[adj_v] == -1:
            queue.append(adj_v)
            distance[adj_v] = distance[v] + 1

check = False

for i in range(len(distance)):
    if distance[i] == k:
        print(i)
        check = True


if not check:
    print(-1)
