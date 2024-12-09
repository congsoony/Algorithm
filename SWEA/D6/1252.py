import sys
import heapq
#sys.stdin = open("input.txt","r")
input = sys.stdin.readline

Test = int(input())
price =[0,1,2,5]

def getCnt(y,x,size):
    global board,n
    cnt = 0
    for i in range(y,y+size):
        for j in range(x,x+size):
            cnt+=board[i][j]
    return cnt
def cover(y,x,size):
    global board,n
    for i in range(y,y+size):
        for j in range(x,x+size):
            board[i][j]=0
for test in range(1,Test+1):
    n = int(input())
    m = int(input())
    board =[[0]*(n+5) for i in range(n+5)]
    l = list(map(int,input().split()))
    pq = []
    for i in range(0,m*2,2):
        board[l[i]][l[i+1]]=1

    for size in range(3,0,-1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                cnt = getCnt(i,j,size)
                if cnt>0 and cnt>=price[size]:
                    heapq.heappush(pq,(-cnt,-size,i,j))
    res= []    
    while pq:
        cnt,size,y,x = heapq.heappop(pq)
        cnt=-cnt
        size = -size
        newcnt = getCnt(y,x,size)
        if newcnt==cnt:
            cover(y,x,size)
            res.append((y,x,size))
        elif newcnt>0:
            for length in range(size,0,-1):
                newcnt = getCnt(y,x,length)
                if newcnt> 0 and newcnt>=price[length]:
                    heapq.heappush(pq,(-newcnt,-length,y,x))
    
    print("#{} {}".format(test,len(res)),end=' ')
    for i in range(len(res)):
        print("{} {} {}".format(res[i][0],res[i][1],res[i][2]),end=' ')
    print()



        