#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> parent;
vector<string> value;
vector<string> split(string &s,char delimiter=' '){
    vector<string> v;
    stringstream ss(s);
    string temp;
    while(getline(ss,temp,delimiter))v.push_back(temp);
    return v;
}

int find(int idx){
    if(parent[idx]==idx)return idx;
    return parent[idx]=find(parent[idx]);
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    if (a<b)//여기서 주의 반드시 a가 작으면 a에 b를 넣고
        parent[a]=b;
    else//아니라면 b에 를 넣음
        parent[b]=a;
}
int getpos(string r,string c){
    return (stoi(r)-1)*50+(stoi(c)-1);
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;

    parent = vector<int>(2500);
    value = vector<string>(2500);
    for(int i=0;i<2500;i++)parent[i]=i;

    for(string &c:commands){
        vector<string> v = split(c);
        if(v[0]=="UPDATE"){
            if(v.size()==4){
                int pos = getpos(v[1],v[2]);
                int idx = find(pos);
                value[idx]=v[3];
            }else{
                for(int i =0;i<2500;i++)
                    if(value[i]==v[1])
                        value[i]=v[2];
            }
        }
        else if(v[0]=="MERGE"){
            int pos1 = getpos(v[1],v[2]);
            int pos2 = getpos(v[3],v[4]);
            int idx1 = find(pos1);
            int idx2 = find(pos2);
            if(value[idx1].size()){
                value[idx2]=value[idx1];
            }
            else if(value[idx2].size()){
                value[idx1]=value[idx2];
            }
            merge(idx1,idx2);
        }
        else if(v[0]=="UNMERGE"){
            int pos = getpos(v[1],v[2]);
            int idx = find(pos);
            string temp = value[idx];
            for(int i=0;i<2500;i++){
                if(idx ==find(i)){
                    parent[i]=i;
                    value[i]="";
                }
            }
            value[pos]=temp;
        }
        else{
            int idx = find(getpos(v[1],v[2]));
            answer.push_back(value[idx].empty()?"EMPTY":value[idx]);
        }
    }
    return answer;
}