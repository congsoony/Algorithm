# import sys
# sys.stdin = open("input.txt","r")
# sys.stdout = open("output.txt","w")
#input = sys.stdin.readline
Test = int(input())
for test in range(Test):
    k = int(input())
    
    s = input().strip()
    l= []
    for i in range(len(s)):
        l.append(s[i:])
    l.sort()
    print('#{} {}'.format(test+1,l[k-1]))
    