import sys
sys.setrecursionlimit(10000)
n = int(input())

def dfs(l,r):
    global s
    if l>=r:
        return True
    L,R = l,r
    while L<R:
        if s[L]==s[R]:
            return False
        L+=1
        R-=1
    mid = (l+r)//2
    return dfs(l,mid-1) and dfs(mid+1,r)

for i in range(n):
    s = input()
    l,r=0,len(s)-1
    res = dfs(l,r)
    print("YES" if res else "NO")
