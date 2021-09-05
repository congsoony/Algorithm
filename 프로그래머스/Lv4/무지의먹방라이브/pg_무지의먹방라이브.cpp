#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<ll, int> a, pair<ll, int> b) {
    return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
    ll sum = 0;
    deque<pair<ll, int>> dq;
    for (int i = 0; i < food_times.size(); i++) {
        dq.push_back({ food_times[i],i });
        sum += (ll)food_times[i];
    }
    if (sum <= k) return -1;
    sort(dq.begin(), dq.end());
    ll before = 0;
    while (!dq.empty()) {
        ll val = dq.size() * (dq.front().first - before);
        if (val > k)
            break;
        k -= val;
        before = dq.front().first;
        dq.pop_front();
    }
    sort(dq.begin(), dq.end(), cmp);
    int ans = dq[k % dq.size()].second;
    return ans+1;
}