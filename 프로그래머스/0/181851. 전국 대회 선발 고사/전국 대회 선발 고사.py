def solution(rank, attendance):
    ranking = 1
    picker = []
    student = []
    for x in range(len(attendance)):
        if not attendance[x]:
            picker.append(x)
    while len(student) < 3:
        for x in range(len(rank)):
            if rank[x] == ranking:
                if x not in picker:
                    student.append(x)
        ranking += 1
    answer = 10000 * student[0] + 100 * student[1] + 1 * student[2]

    return answer


