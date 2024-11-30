#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(11);
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>>pq1,pq2;
    for(vector<int> &p : program){
        pq1.push({p[1],p[0],p[2]});
    }
    ll t1,t2,score1;
    ll t3,t4 ,score2;
    tie(t1,score1,t2)=pq1.top();//호출 ,점수, 실행
    pq1.pop();
    pq2.push({score1,t1,t2});
    ll cur=t1;
    while(!pq2.empty()){
        tie(score2,t3,t4)=pq2.top();
        pq2.pop();
        answer[score2]+=cur-t3;
        cur+=t4;
        while(!pq1.empty()){
            tie(t1,score1,t2) = pq1.top();
            if(cur>=t1){
                pq1.pop();
                pq2.push({score1,t1,t2});
            }
            else if (pq2.empty()&&cur<t1){
                cur=t1;
            }
            else{
                break;
            }
        }
    }
    answer[0]=cur;
    return answer;
}
