#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[200000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);

    int res = 0;
    int l =1,r=2e9;
    while(l<=r){
        int mid = (l+r)/2;
        int cnt =1;
        int pre=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-pre>=mid){
                cnt++;
                pre=arr[i];
            }
        }
        if(cnt>=m){
            l=mid+1;
            res = max(res,mid);
        }
        else{
            r=mid-1;
        }
    }
    cout<<res<<"\n";

    return 0;
}
