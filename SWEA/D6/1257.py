# import sys
# sys.stdin = open("input.txt","r")
# sys.stdout = open("output.txt","w")
#input = sys.stdin.readline
Test = int(input())
for test in range(Test):
    k = int(input())
    
    s = input().strip()
    l = []
    for i in range(1,len(s)+1):
        for j in range(len(s)-i+1):
            l.append(s[j:j+i])
    l = list(set(l))
    l.sort()
    if k<len(l):
        print('#{} {}'.format(test+1,l[k-1]))
    else:
        print('#{} {}'.format(test+1,'none'))

    