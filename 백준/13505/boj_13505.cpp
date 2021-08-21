//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
#define M 30
vector<int> v;
int n;
struct trie {
    trie* children[2];
    trie() {
        memset(children, 0, sizeof(children));
    }
    ~trie() {
        for (int i = 0; i < 2; i++)
            if (children[i])delete children[i];
    }
    void insert(vector<int>& t, int height = 0) {
        if (height >= M)return;
        int next = t[height];
        if (children[next] == NULL)
            children[next] = new trie();
        children[next]->insert(t, height + 1);
    }
    int find(vector<int>& t, int value,int height = 0) {
        if (height >= M)return value;
        int next = t[height];
 
        //현재 해당비트가 켜져있거나 꺼져있다면 반대인것을 찾음
        if (children[!next]) 
            next = !next;
        value ^= (next << (M - height - 1));//그것을 xor해준것이 최대값을 만듦
        return children[next]->find(t, value, height + 1);
    }
};
vector<int> tobinary(int value) {
    vector<int> t(M);
    for (int j = M - 1; j >= 0; j--) {
        t[j] = value % 2;
        value /= 2;
    }
    return t;
}
 
trie tr;
 
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        vector<int> t = tobinary(num);
        tr.insert(t);
    }
}
void solve() {
    int res = 0;
    for (int num : v) {
        vector<int> t = tobinary(num);
        res = max(res, tr.find(t,num));
    }
    cout << res << "\n";
 
  
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    input();
    solve();
}