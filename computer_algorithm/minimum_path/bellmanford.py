'''
Bellmanford is greedy algorithm.
This algorithm is valid on negative weigthed edges too
It used to be implemented in sending packing while routing
It can update local information when it see an edge.

basic operation is 
 d_k[v, u]: shortest path from v to u involving (number <= k) edges
 Base:
  d_1[v, u] = W[v, u]
 Recurrence relation
  d_k+1[v, u] = min(d_k[v, i] + W[i, u]) 


Consderation when we use greedy algorithm.
We shoud check 2 conditions When we use greedy algorithm.
 1) locally optimal choice
 2) No reconsideration
To deal with problem exactly, we need to prove that it is optimal from selecting locally optimal solutions.
'''
INF = int(1e9)

def bellmanford(n, W, F, start_vertex=0, end_vertex=None):
    '''
    Input
        n : the number of vertex in a graph
        W : Weighted directional edges
            W[i][j] : the weigth from i th vertex to j th vertex
        F : F is empty array to store which one is before

    Output
        F : F shows which vertex is just before. F[i]: a vertex just before i th vertex 
        dist : minimum length from start_vertex to each vertices
    
    Time complexity
        O(nm) : n is the number of vertices and m is the number of edges
    '''
    touch = [start_vertex] * n # which vertex is just before. touch[i]: a vertex just before i th vertex
    dist = [INF] * n # dist is the cost from the start_vertex to other_vertices
    
    for i in range(n):
        dist[i] = W[start_vertex][i]
    
    # exception_vertices includes start_vertex 
    #                             and vertices which not have any incomming edges
    # put vertices which not have any incomming edges
    exception_vertices = []
    for i in range(n):
        is_connected = False
        for j in range(n):
            if W[j][i] != INF:
                is_connected = True
        if is_connected == False:
            exception_vertices.append(i)
    
    # put start_vertex in exception_vertices
    if start_vertex not in exception_vertices:
        exception_vertices.append(start_vertex)

    # this looks O(n^3) algorithm. 
    # But, exception_vertices make n^2 to m. m is the number of edges 
    # Then, time complexity changes to O(nm)
    for _ in range(2, n):
        is_changed = False
        for u in [x for x in range(n) if x not in exception_vertices]:
            for i in range(n):
                if dist[u] > dist[i] + W[i][u]:
                    dist[u] = dist[i] + W[i][u]
                    touch[u] = i
                    is_changed = True
        
        # Stop the loop when we can't have any change in dist array.
        if is_changed == False:
            break
    
    F.extend(touch)
    if end_vertex is not None:
        return dist[end_vertex]
    else:
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
cost = bellmanford(n, W, F)
print(F)
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
costs = bellmanford(n, _W, F, start_vertex=cur_city)
costs = [x for x in costs if x != INF]
the_number_of_city_getting_message = len(costs)
time = max(costs)
print(the_number_of_city_getting_message, time)