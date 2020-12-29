'''
Dijkstra is greedy algorithm.
This algorithm is valid on non-negative weigthed edges.

Consderation when we use greedy algorithm.
We shoud check 2 conditions When we use greedy algorithm.
 1) locally optimal choice
 2) No reconsideration
To deal with problem exactly, we need to prove that it is optimal from selecting locally optimal solutions.
'''

from heapq import heappop, heappush

INF = int(1e9)

def dijkstra(n, W, F, start_vertex=0, end_vertex=None):
    '''
    Input
        n : the number of vertex in a graph
        W : Weighted directional edges
            W[i][j] : the weigth from i th vertex to j th vertex
            Shape could be not n by n
        F : F is empty array to store minimum path

    Output
        F : minimum paths
        distance : minimum length from start_vertex to each vertices
    
    Time complexity
        O(nlogn)
    '''
    touch = [start_vertex] * n # which vertex is just before. touch[i]: a vertex just before i th vertex
    distance = [INF] * n # distance is the cost from the start_vertex to other_vertices
    F.clear()
    heap = []
    # type of heap element
    # (distance from start_vertex, closest outcomming vertex, incomming vertex)
    # (distance, u, v)
    # here, distance is 0 from start_vertex to start_vertex
    heappush(heap, (0, start_vertex, start_vertex))

    while heap:
        length, u, v = heappop(heap)
        # skip when distance from start vertex is already set
        if distance[v] != INF:
            continue
        distance[v] = length
        touch[v] = u
        e = (touch[v], v)
        F.append(e)

        if v == end_vertex:
            return distance[v]

        # put connected elements from v vertex in heap
        for vv, w in W[v]:
            # skip when distacne[vv] is set
            if distance[vv] != INF:
                continue
            heap_element = (length + w, v, vv)
            heappush(heap, heap_element)

    return distance


# W = [
#     [0, 7, 4, 6, 1],
#     [INF, 0, INF, INF, INF],
#     [INF, 2, 0, 5, INF],
#     [INF, 3, INF, 0, INF],
#     [INF, INF, INF, 1, 0]
# ]


# n = len(W)
# F = []
# cost = dijkstra(n, W, F)
#print(F)
#print(cost)


with open('input.txt','r') as f:
    content = f.readlines()
    n, m, cur_city = list(map(int, content[0].split()))
    cur_city -= 1
    W = [[] for _ in range(n)]


    for idx in range(m):
        i, j, w = list(map(int, content[idx + 1].split()))
        W[i - 1].append((j - 1, w))

F = []
costs = dijkstra(n, W, F, start_vertex=cur_city)
costs.pop(0)
costs = [x for x in costs if x != INF]
the_number_of_city_getting_message = len(costs)
time = max(costs)
print(the_number_of_city_getting_message, time)
print('path', F)