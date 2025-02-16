import sys
import math
from collections import Counter
input = sys.stdin.readline

n = int(input())
v = [int(input()) for i in range(n)]
gcd = v[0]-v[1]
for i in range(1,n):
    gcd = math.gcd(gcd,v[i]-v[i-1])

total = 0

for i in range(1,n):
    total+= (v[i]-v[i-1])//gcd -1
print(total)