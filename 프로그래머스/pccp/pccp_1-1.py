from collections import Counter
def solution(input_string):
    s = input_string
    answer = ''
    i = 0
    c = Counter()
    while i<len(s):
        j = i+1
        c[s[i]]+=1
        while j<len(s) and s[i]==s[j]:
            j+=1
        i=j
    for i in range(26):
        if c[chr(ord('a')+i)] >=2:
            answer+=chr(ord('a')+i)
    if answer =='':
        return 'N'
    
    return answer
