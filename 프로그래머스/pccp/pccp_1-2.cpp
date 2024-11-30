#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
vector<int>check;
int n,m;
int dfs(int h){
    if(h>=m){
        return 0;
    }
    int res =0;
    for(int i=0;i<n;i++){
        if(check[i]==0){
            check[i]=1;
            res = max(res,dfs(h+1)+arr[i][h]);
            check[i]=0;
        }
    }
    return res;
}
int solution(vector<vector<int>> ability) {
    int answer = 0;
    n = ability.size();
    m = ability[0].size();
    arr = ability;
    check = vector<int>(n);
    return dfs(0);
}

