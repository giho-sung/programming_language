from copy import deepcopy

def dfs(graph, visited, vertex):
    visited[vertex] = True
    print(vertex + 1, end=' ')

    for edge in graph[vertex]:
        if visited[edge] == False:
            dfs(graph, visited, edge)
        

with open('dfs_bfs_baekjoon1260_input3.txt','r') as f:
    content = f.readlines()
    n, m, start_vertex = list(map(int, content[0].split()))
    start_vertex -= 1
    W = [[] for _ in range(n)]

    for idx in range(m):
        i, j = list(map(int, content[idx + 1].split()))
        W[i - 1].append(j - 1)
        W[j - 1].append(i - 1) # undirected graph

'''
import sys
input = sys.stdin.readline

n, m, start_vertex = list(map(int, input().split()))
start_vertex -= 1
W = [[] for _ in range(n)]
for idx in range(m):
    i, j = list(map(int, input().split()))
    W[i - 1].append(j - 1)
    W[j - 1].append(i - 1)
'''
# sort

# DFS 
# ver 1. system call by function
for ww in W:
    ww.sort()

visited = [False] * n
dfs(W, visited, start_vertex)

# DFS
# ver 2. stack
# for ww in W:
#     ww.sort(reverse=True)

# visited = [False] * n

# stack = []
# stack.append(start_vertex)
# while stack:
#     v = stack.pop()
#     if visited[v] == False:
#         print(v + 1, end=' ')
#         visited[v] = True
#     else:
#         continue
#     for edge in W[v]:        
#         if visited[edge] == False:
#             stack.append(edge)

print()

# BFS
# for ww in W:
#     ww.sort()
visited = [False] * n

from collections import deque
q = deque()

q.append(start_vertex)
visited[start_vertex] = True
while q:
    v = q.popleft()
    print(v + 1, end=' ')
    for edge in W[v]:
        if visited[edge] == False:
            q.append(edge)
            visited[edge] = True
