#include <iostream>
#include <vector>
#include <cstring> // memset 사용

using namespace std;

int n, k, target;
vector<int> v;
int dp[1 << 16]; 

int dfs(int bit){
    if(bit==(1<<n)-1)return 1;
    int &cache = dp[bit];
    if(cache!=-1)return cache;

    int sum = 0;
    for(int i=0;i<n;i++)if(bit&(1<<i))sum+=v[i];
    cache = 0;
    sum%=target;

    for(int i =0;i<n;i++){
        if(!(bit&(1<<i))){
            if(sum+v[i]<=target){
                if(dfs(bit|(1<<i)))return cache =1;
            }
        }
    }
    return cache;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    
    
    string res[2]={"No","Yes"};
    cin>>n>>k;
    v = vector<int>(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    if (sum % k != 0) {
        cout << "No\n";
        return 0;
    }

    target = sum / k; // 각 그룹이 가져야 할 목표 합
    memset(dp, -1, sizeof(dp));
    cout<<res[dfs(0)]<<"\n";
}