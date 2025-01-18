from collections import Counter
def totime(s):
    return int(s[0:4])*12*28 + int(s[5:5+2])*28+int(s[8:8+2])

def solution(today, terms, privacies):
    answer = []
    today = totime(today)
    c = Counter()
    for i in range(len(terms)):
        t = terms[i].split()
        c[t[0]]=int(t[1])
    for i in range(len(privacies)):
        p = privacies[i].split()
        t = totime(p[0]) + c[p[1]]*28
        if t<=today:
            answer.append(i+1)
    return answer