//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
struct Trie {
    bool terminal = false;
    unordered_map<char, Trie*> children;
    unordered_map<int, int> m;
    void insert(string& s, int idx = 0) {
        m[s.size() - idx]++;
        if (s[idx] == 0) {
            terminal = true;
            return;
        }
        char next = s[idx];
        if (children[next] == NULL) 
            children[next] = new Trie();
        children[next]->insert(s, idx + 1);
    }
    int find(string& s, int idx = 0) {
        char next = s[idx];
        if (next == '?') return m[s.size() - idx];
        else if(children.count(next)){
            return children[next]->find(s, idx + 1);
        }
        return 0;
    }
};
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie trie,rtrie;
    for (string& s : words) {
        string rs(s.rbegin(), s.rend());
        trie.insert(s);
        rtrie.insert(rs);
    }
    for (string& s : queries) {
        if (s[0] == '?') {
            reverse(s.begin(), s.end());
            answer.push_back(rtrie.find(s));
        }
        else {
            answer.push_back(trie.find(s));
        }
    }
    return answer;
}
