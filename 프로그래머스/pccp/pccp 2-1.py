def solution(command):
    dy =[1,0,-1,0]
    dx = [0,1,0,-1]
    x,y,dir=0,0,0
    d = {'R':1,'L':-1}
    for c in command:
        if c =='G':
            x,y=x+dx[dir],y+dy[dir]
        elif c=='B':
            x,y=x-dx[dir],y-dy[dir]
        else:
            dir =(dir+4+d[c])%4
    return [x,y]