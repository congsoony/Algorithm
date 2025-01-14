from collections import defaultdict
#import sys
#sys.stdin = open("input.txt","r")
Test = int(input())
for test in range(1,Test+1):
    n,p= map(int,input().split())
    res =1
    while p:
        res*=n//p
        n-=n//p
        p-=1
    print('#%d %d'%(test,res))