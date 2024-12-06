#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

vector<pair<string,int>> v;
unordered_set<int> check;
int res = 0;
void input(){
    int test;
    cin>>test;
    v.resize(test);
    for(int i =0;i<test;i++)cin>>v[i].first>>v[i].second;
}
void dfs(string &num,int cnt,int h=0){
    if(h>=cnt ||h>=num.size()){
        res = max(res,stoi(num));
        return;
    }
    for(int i=0;i<num.size();i++){
        for(int j =i+1;j<num.size();j++){
            swap(num[i],num[j]);
            dfs(num,cnt,h+1);
            swap(num[i],num[j]);   
        }
    }
    
}
void solve(){

    for(int t=0;t<v.size();t++){
        check.clear();
        res = 0;
        dfs(v[t].first,v[t].second);
        cout<<"#"<<t+1<<" "<<res<<"\n";
    }
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    input();
    solve(); 
    
    
    
}