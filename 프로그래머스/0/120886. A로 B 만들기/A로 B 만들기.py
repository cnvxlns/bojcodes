def solution(before, after):
    a = [0] * 130
    b = [0] * 130
    for i in before:
        a[ord(i)] += 1
    for i in after:
        b[ord(i)] += 1
        
    if a == b:
        return 1
    else:
        return 0