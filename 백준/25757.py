import sys
from collections import Counter
input = sys.stdin.readline
n,t = input().split()
n= int(n)

l = [input() for i in range(n)]
c = Counter(l)
m = Counter({'Y':1,'F':2,'O':3})
print(len(c)//m[t])