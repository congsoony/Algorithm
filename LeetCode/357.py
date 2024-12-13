class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        if n==0 or n==1:
            return 10**n
        res =10
        for i in range(1,n):
            c = 9
            t = 9
            for j in range(i):
                c*=t
                t-=1
            res +=c
        return res
