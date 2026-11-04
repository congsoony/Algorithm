#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<string> board(n);
    vector<int> v;
    int posy[10]={0};
    int posx[10]={0};
    int sy,sx,ey,ex;
    int cnt = 0;
    for(int i =0;i<n;i++){
        cin>>board[i];
        for(int j =0;j<n;j++){
            if(board[i][j]=='S'){
                tie(sy,sx)={i,j};
            }
            else if(board[i][j]=='E'){
                tie(ey,ex)={i,j};
            }
            else if(isdigit(board[i][j])){
                cnt++;
                int t = board[i][j]-'0';
                tie(posy[t],posx[t])={i,j};
                v.push_back(t);
            }
        }
    }
    if(cnt<3){
        cout<<-1<<"\n";
        return 0;
    }
    vector<int> p(cnt,1);
    sort(v.begin(),v.end());
    for(int i =0;i<3;i++)p[i]=0;
    int res =1e9;
    do{
        vector<pair<int,int>> v2 = {{sy,sx}};
        for(int i =0;i<cnt;i++){
            if(p[i]==0){
                v2.push_back({posy[v[i]] , posx[v[i]]});
            }
        }
        v2.push_back({ey,ex});
        int sum=0;
        for(int i =1;i<v2.size();i++){
            sum+=abs(v2[i].first - v2[i-1].first) + abs(v2[i].second - v2[i-1].second);
        }
        res = min(res,sum);
    }while(next_permutation(p.begin(),p.end()));
    cout<<res<<"\n";
}