import sys
input =sys.stdin.readline
print = sys.stdout.write
n= int(input())

l = [int(input())for i in range(n)]
num = [0]*2500000
t = 1000000
for i in l:num[i+1000000]+=1

for i in range(-1000000,1000001):
    while num[i+t]:
        print('%d\n'%(i))
        num[i+t]-=1
