from collections import deque

n, k = map(int, input().split())


graph = []
initial_nums = []
for i in range(n):
    nums = list(map(int, input().split()))
    graph.append(nums)
    for j in range(len(nums)):
        if nums[j] != 0:
            initial_nums.append((i, j, nums[j], 0))


initial_nums.sort(key=lambda item:item[2])

queue = deque(initial_nums)
s, yp, xp = map(int, input().split())
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]


while queue:
    y, x, v, t = queue.popleft()
    if t == s:
        break

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue

        if graph[ny][nx] == 0:
            graph[ny][nx] = v
            queue.append((ny, nx, v, t + 1))

virus = graph[yp-1][xp-1]
if virus == 0:
    print(0)
else:
    print(virus)
