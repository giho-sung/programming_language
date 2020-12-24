'''
Floyd's algorithm is greedy algorithm.
This algorithm is valid on negative weigthed edges too. but not cycle

Basic operation is 
 D_ab = min(D_ab, D_ak + D_kb )
 

Consderation when we use greedy algorithm.
We shoud check 2 conditions When we use greedy algorithm.
 1) locally optimal choice
 2) No reconsideration
To deal with problem exactly, we need to prove that it is optimal from selecting locally optimal solutions.
'''
from copy import deepcopy
INF = int(1e9)

def floyd(n, W, F):
    '''
    Input
        n : the number of vertex in a graph
        W : Weighted directional edges
            W[i][j] : the weigth from i th vertex to j th vertex
        F : F is empty array to store which one is before
            here, it just empty array

    Output
        F : F shows which vertex is just before. F[i]: a vertex just before i th vertex
            here, it just empty array 
        dist : minimum length from start_vertex to each vertices
    
    Time complexity
        O(n^3) : n is the number of vertices
    '''

    # D_ab = min(D_ab, D_ak + D_kb )

    # F.clear()
    dist = deepcopy(W)

    for k in range(n):
        for a in range(n):
            for b in range(n):
                if a != b and a != k and b != k:
                    if dist[a][b] > dist[a][k] + dist[k][b]:
                        dist[a][b] = dist[a][k] + dist[k][b]
    return dist



    


W = [
    [0, 7, 4, 6, 1],
    [INF, 0, INF, INF, INF],
    [INF, 2, 0, 5, INF],
    [INF, 3, INF, 0, INF],
    [INF, INF, INF, 1, 0]
]


n = len(W)
F = []
cost = floyd(n, W, F)
# print(F)
print(cost)

with open('input.txt','r') as f:
    content = f.readlines()
    n, m, cur_city = list(map(int, content[0].split()))
    cur_city -= 1
    _W = [[INF] * n for _ in range(n)]

    for idx in range(m):
        i, j, w = list(map(int, content[idx + 1].split()))
        _W[i - 1][j - 1] = w

F = []
costs = floyd(n, _W, F)
print(costs)
#costs = [x for x in costs if x != INF]
#the_number_of_city_getting_message = len(costs)
#time = max(costs)
#print(the_number_of_city_getting_message, time)