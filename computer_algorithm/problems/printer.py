'''
This printer problem is sort of priority circular queue problem. 
For simplification, I used cur_position to mimic circular queue in an array.

This problem is in programmer.co.kr
It is called 프린터(printer)
'''

def get_max_index(array, cur_position):
    # get max value
    max_value = max(array)[0]
    # searching max from cur_position to end
    for index in range(cur_position, len(array)):
        if array[index][0] == max_value:
            return index
    for index in range(cur_position):
        if array[index][0] == max_value:
            return index
    
    return 0

def solution(priorities, location):
    priorities = [(priority, i) for i, priority in enumerate(priorities)]
    
    count = 0
    cur_position = 0
    l = len(priorities)
    while priorities:
        # printing
        max_index = get_max_index(priorities, cur_position)
        priority, i = priorities.pop(max_index)
        count += 1
        if len(priorities) != 0:
            cur_position = max_index % len(priorities)        
        # if i == location, answer = count, break
        if i == location:
            answer = count
            break
    
    return answer

priorities_list = [[2, 1, 3, 2], [1, 1, 9, 1, 1, 1]]
location_list = [2, 0]
answers = [1, 5]

for priorities, location in zip(priorities_list, location_list):
    print(solution(priorities, location))
