def to_dec(binnum):
    res = 0
    for i in range(len(binnum)):
        if binnum[i] == '1':
            res += (1 << (len(binnum) - i - 1))
    return res

def to_bin_char(num):
    res = ''
    if num == 0:
        return '0'
    while num > 0:
        res = ('1' if num % 2 else '0') + res
        num //= 2
    return res

def solution(bin1, bin2):
    num1 = to_dec(bin1)
    num2 = to_dec(bin2)
    answer = to_bin_char(num1 + num2)
    return answer
