#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

struct Edge {
    int to;
    int wA, wB;
};

static vector<ll> dijkstra_to_N(int N, const vector<vector<pair<int,int>>>& rev) {
    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[N] = 0;
    pq.push({0, N});

    while (!pq.empty()) {
        auto [d, x] = pq.top(); pq.pop();
        if (d != dist[x]) continue;

        for (auto [prev, w] : rev[x]) { // prev -> x with weight w
            ll nd = d + (ll)w;
            if (nd < dist[prev]) {
                dist[prev] = nd;
                pq.push({nd, prev});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> g(N + 1);
    vector<vector<pair<int,int>>> revA(N + 1), revB(N + 1);

    struct Raw { int u,v,a,b; };
    vector<Raw> edges;
    edges.reserve(M);

    for (int i = 0; i < M; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        g[u].push_back({v, a, b});
        revA[v].push_back({u, a});
        revB[v].push_back({u, b});
        edges.push_back({u, v, a, b});
    }

    // 1) dist to N in graph A and B (run on reversed graph from N)
    vector<ll> distA = dijkstra_to_N(N, revA);
    vector<ll> distB = dijkstra_to_N(N, revB);

    // 2) Dijkstra on warning-cost graph (edge cost = 0..2)
    vector<int> distW(N + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    distW[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cw, u] = pq.top(); pq.pop();
        if (cw != distW[u]) continue;
        if (u == N) break;

        for (const auto &e : g[u]) {
            int v = e.to;

            int warnA = 1;
            if (distA[u] != INF && distA[v] != INF) {
                if (distA[u] == distA[v] + (ll)e.wA) warnA = 0;
            }

            int warnB = 1;
            if (distB[u] != INF && distB[v] != INF) {
                if (distB[u] == distB[v] + (ll)e.wB) warnB = 0;
            }

            int cost = warnA + warnB; // 0..2
            int nw = cw + cost;
            if (nw < distW[v]) {
                distW[v] = nw;
                pq.push({nw, v});
            }
        }
    }

    cout << distW[N] << "\n";
    return 0;
}