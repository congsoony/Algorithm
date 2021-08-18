//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
 
string Tolower(string s) {
    string res;
    for (char c : s)
        res += tolower(c);
    return res;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    string pattern[] = { "[^\\d]+","\\d{1,5}",".*" };
    smatch match;
    vector<tuple<string, int, int, string>> fv;
    for (int i = 0; i < files.size(); i++) {
        string s = files[i];
        vector<string> v;
        for (int i = 0; i < 3; i++) {
            regex_search(s, match, regex(pattern[i]));
            v.push_back(match[0]);
            s = match.suffix();
        }
 
        fv.push_back({Tolower(v[0]),stoi(v[1]),i,files[i] });
    }
    sort(fv.begin(), fv.end());
    for (int i = 0; i < fv.size(); i++)
        answer.push_back(get<3>(fv[i]));
    return answer;
}
