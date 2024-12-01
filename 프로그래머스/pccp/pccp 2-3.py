from collections import deque
def solution(menu, order, k):
    res = 0
    q = deque()
    idx = 0
    finish = k*(len(order)-1)
    t = 0
    while t<=finish:
        if q:
            q[0]-=1
            if q[0]==0:
                q.popleft()
        if t%k==0:
            q.append(menu[order[idx]])
            idx+=1
        res = max(res,len(q))
        t+=1
    return res

menu,order ,k = [5]	,[0,0,0,0,0]	,5
print(solution(menu,order,k))