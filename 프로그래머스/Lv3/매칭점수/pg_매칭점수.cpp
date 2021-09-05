#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> basis, outer;
unordered_map<string, vector<string>> link;
string toLower(string& s) {
    string res;
    for (char c : s)
        res += tolower(c);
    return res;
}
string getAddress(string& page) {
    string address = "<meta property=\"og:url\" content=\"(.*?)\"\\s*/>";
    regex meta(address);
    smatch match;
    regex_search(page, match, meta);
    return match[1];
}
int getBasis(string& page, string word) {
    regex re("[a-zA-Z]+");
    word = toLower(word);
    sregex_iterator it(page.begin(), page.end(), re), end;
    int cnt = 0;
    while (it != end) {
        string s = it->str();
        s = toLower(s);
        if (s == word)
            cnt++;
        it++;
    }
    return cnt;
}
vector<string> getOuters(string& page) {
    string ref = "<a href=\"(.*?)\">";
    regex re(ref);
    sregex_token_iterator it(page.begin(), page.end(), re, 1), end;
    return vector<string>(it, end);
}
int solution(string word, vector<string> pages) {
    int answer = 0;
    vector<pair<double, int>> res;
    vector<string> av;
    //기본점수 외부링크수
    for (string page : pages) {
        //해당 url
        string address = getAddress(page);
        av.push_back(address);
        //기본점수
        int base = getBasis(page, word);
        //외부링크
        vector<string> ov = getOuters(page);
        basis[address] = base;
        outer[address] = ov.size();
        for (int i = 0; i < ov.size(); i++) {
            link[ov[i]].push_back(address);
        }
    }
    //매칭점수 결과
    for (int i = 0; i < av.size(); i++) {
        double matching = 0;
        for (string s : link[av[i]]) {
            matching += (double)basis[s] / (double)outer[s];
        }
        res.push_back({ -matching - basis[av[i]],i });
    }
    sort(res.begin(), res.end());
    return res[0].second;
}
