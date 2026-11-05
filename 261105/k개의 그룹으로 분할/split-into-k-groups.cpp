#include <iostream>
#include <vector>
#include <cstring> // memset 사용

using namespace std;

int n, k, target;
vector<int> v;
int dp[1 << 16][17]; 

int dfs(int bit,int cnt,int sum){
    if(cnt==k)return 1;
    int &cache = dp[bit][cnt];
    if(cache!=-1)return cache;

    if(sum==target) return cache = dfs(bit,cnt+1,sum);
    cache = 0;
    for(int i =0;i<n;i++){
        if(!(bit &(1<<i))){
            if(sum+v[i]<=target){
                if(dfs(bit|1<<i,cnt,sum+v[i])){
                    return cache =1;
                }
            }
        }
    }
    return cache;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    
    
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
    cout<<res[dfs(0,0,0)]<<"\n";
}