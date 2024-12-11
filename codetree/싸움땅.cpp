#include <bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<ll> gun[30][30];
ll n,m,k;
vector<vector<ll>> people;
vector<ll> point;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
void input(){
    cin>>n>>m>>k;
    ll num;
    for(int i=0;i<n ;i++){
        for(int j=0;j<n;j++){
            cin>>num;
            gun[i][j].push(num);
        }
    }
    people = vector<vector<ll>>(m);
    ll y,x,d,s;
    for(int i =0;i<m;i++){
        people[i]=vector<ll>(5);
        for(int j=0;j<4;j++){
            cin>>people[i][j];
        }
        people[i][0]--;
        people[i][1]--;
    }
}
int exist(int y,int x,int idx){
    for(int i=0;i<m;i++){
        if(idx==i)continue;
        if(people[i][0]==y &&people[i][1]==x)return i;
    }
    return -1;
}
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<n;
}
void pick(int idx,int y,int x){
    gun[y][x].push(people[idx][4]);
    people[idx][4]=gun[y][x].top();
    gun[y][x].pop();
}

pair<ll,ll> fight(int idx,int idx2){
    if(people[idx][3]+people[idx][4] == people[idx2][3]+people[idx2][4]){
        if(people[idx][3]>people[idx2][3]){
            return {idx,idx2};
        }
        else{
            return {idx2,idx};
        }
    }
    else if(people[idx][3]+people[idx][4] > people[idx2][3]+people[idx2][4]){
        return {idx,idx2};
    }

    return {idx2,idx};
}
void losermove(int ny,int nx,int lose){
    gun[ny][nx].push(people[lose][4]);
    people[lose][4]=0;
    for(int i =0;i<4;i++){
        int dir = (people[lose][2]+i)%4;
        int ny2 = ny + dy[dir];
        int nx2 = nx+dx[dir];
        if(isrange(ny2,nx2) &&exist(ny2,nx2,lose)==-1){
            people[lose][0]=ny2;
            people[lose][1]=nx2;
            people[lose][2]=dir;
            pick(lose,ny2,nx2);
            break;
        }
    }
}

void move(int idx){
    ll y,x,d,s,g;
    tie(y,x,d,s,g) = {people[idx][0],people[idx][1],people[idx][2],people[idx][3],people[idx][4]};
    int ny = y+dy[d];
    int nx= x+dx[d];
    //밖으로 나갈경우 방향만 바꿈
    if(!isrange(ny,nx)){
        d = (d+2)%4;
        ny =y+dy[d];
        nx =x+dx[d];
        people[idx][2]=d;
    }

    int f = exist(ny,nx,idx);
    if(f ==-1){
        pick(idx,ny,nx);
        people[idx][0]=ny;
        people[idx][1]=nx;
        people[idx][2]=d;
    }
    else{
        ll win,lose;
        tie(win,lose) =fight(idx,f);
        point[win]+=people[win][3]+people[win][4] - people[lose][3]-people[lose][4];
        if(idx==win){
            people[idx][0]=ny;
            people[idx][1]=nx;
            people[idx][2]=d;
            losermove(ny,nx,f);
            pick(idx,ny,nx);
        }
        else{
            losermove(ny,nx,idx);
            pick(f,ny,nx);
        }
    }
}
void solve(){
    point= vector<ll>(m);
    while(k--){
        for(int i=0;i<m;i++){
            move(i);
        }
    }
    for(int i =0;i<m;i++){
        cout<<point[i]<<" ";
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    input();
    solve();

 
}
