#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
unordered_map<int,list<int>::iterator> pos;
int main() {
    freopen("input.txt","r",stdin);
    int q;
    list<int> l={1};
    pos[1]=l.begin();
    cin>>q;
    int a,b,c;
    int cnt = 2;
    for(int i =0;i<q;i++){
        cin>>a>>b;
        if(a!=3){
            cin>>c;
            list<int> l2;
            for(int j =0;j<c;j++){
                l2.push_back(cnt);
                pos[cnt++]=prev(l2.end());
            }
            if(a==1){
                l.splice(next(pos[b]),l2);
            }
            else{
                l.splice(pos[b],l2);
            }
        }
        else{
            auto left = prev(pos[b]);
            auto right = next(pos[b]);
            
            if(left==l.end() || right==l.end())
                cout<<-1<<"\n";
            else
                cout<<*left<<" "<<*right<<"\n";
        }
    }
}