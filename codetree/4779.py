import sys
#sys.stdin = open("input.txt","r")
def dfs(l):
    if len(l)==1:
        print(l[0],end='')
        return
    dfs(l[:len(l)//3])
    for i in range(len(l)//3,len(l)*2//3):print(' ',end='')
    dfs(l[len(l)*2//3:])
while True:
    try:
        n = int(input())
        l = list('-'*(3**n))
        dfs(l)
        print()
    except:
        break



