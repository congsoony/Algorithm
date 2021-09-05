//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
int tomin(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}
string totime(int time) {
    string h = to_string(time/60);
    string m = to_string(time % 60);
    if (h.size() == 1)h = "0" + h;
    if (m.size() == 1)m = "0" + m;
    return h + ":" + m;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> v;
    for (string s : timetable)
        v.push_back(tomin(s));
    sort(v.begin(), v.end());//먼저오는 사람이 탈수있도록 정렬
    int idx = 0;
    for (int i = 0; i < n; i++) {
        int start = tomin("09:00") + i * t;
        int M = m;
        //최대 m명까지 태우고 버스가 오는시간이전에 대기하고있으면 버스태움
        while (M && idx < v.size() && v[idx] <= start) {
            idx++;
            M--;
        }
 
        //마지막에 내가타야함
        if (i == n - 1) {
            if (M) {//자리가 있으면 버스가 오는정각에 타면됨
                answer = totime(start);
            }
            else {//자리가 없다면 마지막에 탔던사람보다 1분일찍와서 새치기
                answer = totime(v[idx - 1] - 1);
            }
        }
    }
    return answer;
}