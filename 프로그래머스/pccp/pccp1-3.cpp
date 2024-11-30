#include<bits/stdc++.h>
using namespace std;
vector<string> s={"RR","Rr","Rr","rr"};
string dfs(int h,int idx){
    if(h==0)return "Rr";
    if(h==1)return s[idx%4];
    string d = dfs(h-1,idx/4);
    if(d!="Rr")return d;
    return s[idx%4];
}
vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for(int i =0;i<queries.size();i++){
        answer.push_back(dfs(queries[i][0]-1,queries[i][1]-1));
    }
    return answer;
}