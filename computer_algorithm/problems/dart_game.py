'''
This dart game problem is just to handle string. 

This problem is in programmer.co.kr
It is called dart game(다트 게임)
'''

def chop_int(string):
    for i in range(len(string)):
        if '0' <= string[i] <= '9':
            pass
        else:
            break
    integer = int(''.join(string[:i]))
    for j in range(i):
        string.pop(0)
    return integer

def chop_bonus(string):
    bonus = string[0]
    string.pop(0)
    if bonus == 'S':
        return 1
    if bonus == 'D':
        return 2
    if bonus == 'T':
        return 3

def take_option(string, score, i):
    if len(string) == 0:
        return
    option = string[0]
    if option != '*' and option != '#':
        return
    string.pop(0)
    if option == '*':
        score[i] *= 2
        if i >= 1:
            score[i - 1] *= 2
        return
    if option == '#':
        score[i] *= -1
    

def solution(dartResult):
    
    dartResult = list(dartResult)
    
    score = [0] * 3
    for i in range(3):
        score[i] = chop_int(dartResult)
        score[i] **= chop_bonus(dartResult)
        take_option(dartResult, score, i)
        
    answer = sum(score)
    return answer

dartResults = ['1S2D*3T', '1D2S#10S', '1D2S0T', '1S*2T*3S', '1D#2S*3S', '1T2D3D#', '1D2S3T*']
answers = [37, 9, 3, 23, 5, -4, 59]

for dartResult in dartResults:
    print(solution(dartResult))