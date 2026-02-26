#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<long long> v(n+2),pre(n+2),suf(n+2);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i]=pre[i-1]+v[i];
    }

    if(pre[n]%4!=0){
        cout<<0<<endl;
        return 0;
    }
    long long t = (pre[n] / 4);
    for (int i = n-1; i >= 1; i--) {
        suf[i]=suf[i+1]+(pre[i]==t*3);
    }
    long long res = 0,cnt=0;
    for (int i = 2; i <= n-2; i++) {
        if(pre[i-1]==pre[n]/4){
            cnt++;
        }
        if(pre[i]==t*2){
            res+=suf[i+1]*cnt;
        }
    }
    cout<<res<<"\n";


}