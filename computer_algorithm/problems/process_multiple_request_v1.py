'''
In the programmers.co.kr, problem '디스크 컨트롤러' disk controller
'''

# minimizzing wait time
# process_time = wait_time + processing_time
# wait_time = start_time - request_time
# process_time = start_time - request_time + processing_time
#     start_time >= request_time

from heapq import heappush, heappop


def solution(jobs):
    
    jobs.sort(key=lambda x: x[0])
    pre_time = -1
    cur_time = jobs[0][0]
    h = []
    accum_processed_time = 0
    next_round_put_idx = 0
    # pick smallest precessing_time work if possible
    for _ in range(len(jobs) * 2):
        # find jobs which have pre_time < requeset_time <= cur_time
        # if don't find, pop heap
        # if no heap element, push closest element
        is_start = False
        for i in range(next_round_put_idx, len(jobs)):
            if not is_start:
                if pre_time < jobs[i][0] <= cur_time:
                    is_start = True
                    put_start_idx = i
                    put_last_idx = i
            else:
                if jobs[i][0] <= cur_time:
                    put_last_idx = i
                else:
                    break
        
        if is_start:
            # put the jobs to the heap with value as processing_time
            for request_time, process_time in jobs[put_start_idx:put_last_idx + 1]:
                heappush(h, (process_time, request_time))
            next_round_put_idx = put_last_idx + 1
        
        # end_condition
        if not h and next_round_put_idx >= len(jobs):
            break
            
        if h:   
            # pop an element which have lowest processing_time in the heap
            process_time, request_time = heappop(h)
            # do a job
            pre_time = cur_time
            cur_time += process_time
            accum_processed_time += cur_time - request_time
        else:
            # push cur_time cloest_element to process
            pre_time = pre_time
            cur_time = jobs[next_round_put_idx][0]
            continue

        
        
    answer = accum_processed_time // len(jobs)    
        
    
    return answer


jobs = [[0, 3], [1, 9], [2, 6]] # answer is 9
print(solution(jobs))
