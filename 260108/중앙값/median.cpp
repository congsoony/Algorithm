#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    int test;
    int n;
    cin>>test;
    while(test--){
        priority_queue<int> maxheap;
        priority_queue<int,vector<int>,greater<int>> minheap;
        cin>>n;
        int a;
        for(int i =0;i<n;i++){
            cin>>a;
            if(minheap.size()==maxheap.size()){
                minheap.push(a);
            }
            else{
                maxheap.push(a);
            }

            if(!minheap.empty()&&!maxheap.empty() && maxheap.top()>minheap.top()){
                int x= maxheap.top();
                maxheap.pop();
                int y = minheap.top();
                minheap.pop();
                
                minheap.push(x);
                maxheap.push(y);
            }
            if(i%2==0){
                cout<<minheap.top()<<" ";
            }
        }
        cout<<"\n";
    }

}