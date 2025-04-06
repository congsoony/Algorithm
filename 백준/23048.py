n = int(input())

prime = [False]*(n+5)
prime[1]=1
color = 1
for i in range(2,n+1):
    if prime[i]==False:
        color+=1
        prime[i]=color
        for j in range(i*2,n+1,i):
            prime[j]=color

print(color)
for i in range(1,n+1):
    print(prime[i],end=' ')