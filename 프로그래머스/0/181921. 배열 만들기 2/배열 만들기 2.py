def solution(l, r):
    answer = []
    for i in range(l, r + 1):
        flag = 0
        for j in str(i):
            if j != '0' and j != '5':
                flag = 1
                break
        if not flag:
            answer.append(i)

    if len(answer) == 0:
        answer.append(-1)

    return answer
            