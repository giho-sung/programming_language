from collections import deque

def kruskal(n, m, edges, F):
    '''
    Input
        n : the number of vertices
        m : the number of edges
        edges : pairs which have undirectional edges and cost of each edges
                (i, j, w)
        F : empty list to store edges which build a minimum spanning tree
    
    Output
        F : edges which build a minimum spanning tree
        Return : sum of weigths building a minimum spanning tree 
    '''
    root_list = [x for x in range(n)]
    F.clear()
    edges.sort(key=lambda x: x[2])

    q = deque(edges)
    sum = 0
    while q:
        i, j, w = q.popleft()
        i_root = find(root_list, i)
        j_root = find(root_list, j)
        # if i and j have different roots, merge those roots
        if i_root != j_root:
            merge(root_list, i_root, j_root)
            F.append((i, j))
            sum += w
        
        # all vertices are connected, building a minimum spannning tree
        if len(F) == n - 1:
            break
    
    return sum


def find(root_list, i):
    if root_list[i] == i:
        return i
    return find(root_list, root_list[i])

def merge(root_list, i_root, j_root):
    # check i and j are root
    assert root_list[i_root] == i_root and root_list[j_root] == j_root, 'Error in merge: i_root or j_root could not be root'

    # find depth of i_root and j_root
    depths = [0] * len(root_list)
    for parent in root_list:
        count = 1
        while parent != root_list[parent]:
            parent = root_list[parent]
            count += 1
        if count > depths[parent]:
            depths[parent] = count
    
    # merge two vertices. vertex which have higher depth is still root
    # to lower depth of connections.
    if depths[i_root] < depths[j_root]:
        root_list[i_root] = j_root
    else:
        root_list[j_root] = i_root




def solution(n, costs):

    m = len(costs)
    F =[]
    return kruskal(n, m, costs, F)



n = 4
costs = [[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]	


print(solution(n,costs))