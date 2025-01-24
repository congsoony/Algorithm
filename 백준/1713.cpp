#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
map<int,pair<int,int>> picture;
void input(){
    cin>>n>>m;
    v= vector<int>(m);
    for(int i=0;i<m;i++)cin>>v[i];
}
void solve(){

    for(int i=0;i<m;i++){

        int num= v[i];
        if(picture.count(num)){
            picture[num].first++;
            continue;
        }
        if(picture.size()<n){
            picture[num]={1,i};
            continue;
        }
        int who=0;
        int minidx=1e8;
        int mincnt = 1e8;
        for(auto p : picture){
            if(p.second.first<mincnt ||(p.second.first==mincnt &&p.second.second<minidx)){
                who=p.first;
                mincnt = p.second.first;
                minidx = p.second.second;
            }
        }
        picture.erase(who);
        picture[num]={1,i};
    }
    for(auto p : picture){
        cout<<p.first<<" ";
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();

}