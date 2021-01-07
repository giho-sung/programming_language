'''
In the programmers.co.kr, problem '디스크 컨트롤러' disk controller
'''
from heapq import heappush, heappop
from collections import deque

def solution(jobs):
    
    jobs.sort(key=lambda x: x[0])
    cur_time = 0 # min time set for start. jobs[0][0] is also ok
    h = []
    accum_processed_time = 0
    q = deque(jobs)

    while q or h:
        # for a loop, it processes a job.

        # if no candidate to pop in the heap, push cur_time 
        if q and q[0][0] > cur_time and not h:
            cur_time = q[0][0]
        
        # push elements to heap if condition
        while q and q[0][0] <= cur_time:
            request_time, process_time = q.popleft()
            heappush(h, (process_time, request_time))
          
        # pop an element which have lowest process_time in the heap
        process_time, request_time = heappop(h)
        # do a job
        cur_time += process_time
        accum_processed_time += cur_time - request_time
        
    answer = accum_processed_time // len(jobs)    
        
    
    return answer

jobs = [[0, 3], [1, 9], [2, 6]] # answer is 9
print(solution(jobs))