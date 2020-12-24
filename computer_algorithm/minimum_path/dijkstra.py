'''
Dijkstra is greedy algorithm.
This algorithm is valid on non-negative weigthed edges.

Consderation when we use greedy algorithm.
We shoud check 2 conditions When we use greedy algorithm.
 1) locally optimal choice
 2) No reconsideration
To deal with problem exactly, we need to prove that it is optimal from selecting locally optimal solutions.
'''
INF = int(1e9)

def dijkstra(n, W, F, start_vertex=0, end_vertex=None):
    '''
    Input
        n : the number of vertex in a graph
        W : Weighted directional edges
            W[i][j] : the weigth from i th vertex to j th vertex
        F : F is empty array to store minimum path

    Output
        F : minimum paths
        cost_to_vertex : minimum length from start_vertex to each vertices
    
    Time complexity
        O(n^2)
    '''
    touch = [start_vertex] * n # which vertex is just before. touch[i]: a vertex just before i th vertex
    length = [INF] * n # length is the cost from the start_vertex to other_vertices
    cost_to_vertex = [INF] * n
    cost_to_vertex[start_vertex] = W[start_vertex][start_vertex]
    F.clear()
    
    # initial length setting from start_vertex
    min_len = INF
    near = None
    for i in range(n):
        length[i] = W[start_vertex][i]
    
    length[start_vertex] = -1

    for _ in range(n - 1):
        min_len = INF

        for i in range(n):
            if 0 <= length[i] < min_len:
                min_len = length[i]
                near = i # near can't be start_vertex and choosen ones which are length[i] == -1.
        
        e = (touch[near], near)
        F.append(e)
        cost_to_vertex[near] = length[near]
        # end condition
        if near == end_vertex:
            return cost_to_vertex[near]

        for i in range(n):
            if length[near] + W[near][i] < length[i]:
                length[i] = length[near] + W[near][i]
                touch[i] = near
        length[near] = -1

    return cost_to_vertex


W = [
    [0, 7, 4, 6, 1],
    [INF, 0, INF, INF, INF],
    [INF, 2, 0, 5, INF],
    [INF, 3, INF, 0, INF],
    [INF, INF, INF, 1, 0]
]


n = len(W)
F = []
cost = dijkstra(n, W, F)
#print(F)
#print(cost)


with open('input.txt','r') as f:
    content = f.readlines()
    n, m, cur_city = list(map(int, content[0].split()))
    cur_city -= 1
    _W = [[INF] * n for _ in range(n)]

    for idx in range(m):
        i, j, w = list(map(int, content[idx + 1].split()))
        _W[i - 1][j - 1] = w

F = []
costs = dijkstra(n, _W, F, start_vertex=cur_city)
costs = [x for x in costs if x != INF]
the_number_of_city_getting_message = len(costs)
time = max(costs)
print(the_number_of_city_getting_message, time)