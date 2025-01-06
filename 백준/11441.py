import sys
input=sys.stdin.readline
n= int(input())
l = [0]+list(map(int,input().split()))
for i in range(n):l[i+1]+=l[i]
m=int(input())
for i in range(m):
    a,b=map(int,input().split())
    print(l[b]-l[a-1])