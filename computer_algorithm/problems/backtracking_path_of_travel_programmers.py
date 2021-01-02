'''
Backtracking is DFS with heuristic selection. 
It should be restore previous states if DFS fails finding solution.
Here, heuristic selection is 'def promising(ticket, a_visited, path)'
      Restoring previous states is conducted in 2 lines below # back to previous state

This problem is in programmer.co.kr
It called 여행경로(path of travel)
'''

def promising(ticket, a_visited, path):
    # not promising
    # 1. ticket is already used
    # 2. the end of path is not same with the start of ticket.
    if a_visited == True:
        return False
    if path[-1] != ticket[0]:
        return False
    return True

def dfs_backtracking_travel_plan(tickets, visited, n, path):
    if len(path) == n + 1:
        return

    for i in range(n):
        if promising(tickets[i], visited[i], path):
            path.append(tickets[i][1])
            visited[i] = True            
            dfs_backtracking_travel_plan(tickets, visited, n, path)
            if len(path) == n + 1:
                return
            # back to previous state
            path.pop()
            visited[i] = False
            
def solution(tickets):
    answer = []
    tickets.sort(key=lambda x: x[1])
    tickets.sort(key=lambda x: x[0])

    n = len(tickets)
    visited = [False] * n
    stack = []
    stack.append('ICN')

    dfs_backtracking_travel_plan(tickets, visited, n, stack)

    answer = stack

    return answer


tickets1 = [['ICN', 'SFO'], ['ICN', 'ATL'], ['SFO', 'ATL'], ['ATL', 'ICN'], ['ATL','SFO']]	
tickets = [["ICN", "B"], ["B", "C"], ["C", "ICN"], ["ICN", "D"], ["ICN", "E"], ["E", "F"]]
print(solution(tickets1))