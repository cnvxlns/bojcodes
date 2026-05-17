#include <string>
#include <vector>
#include <queue>

#define ll long long

using namespace std;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

vi dijkstra(vvpii &G, int startnode, int n){
    vi dist(n + 1, 1e9);
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0, startnode});
    dist[startnode] = 0;
    while(!pq.empty()){
        auto [curdist, curnode] = pq.top(); pq.pop();
        if(curdist > dist[curnode]){
            continue;
        }
        for(auto [nextdist, nextnode]: G[curnode]){
            auto newdist = nextdist + curdist;
            if(newdist < dist[nextnode]){
                dist[nextnode] = newdist;
                pq.push({newdist, nextnode});
            }
        }
    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vvpii G(n + 1);
    for(const auto &i: fares){
        G[i[0]].push_back({i[2], i[1]});
        G[i[1]].push_back({i[2], i[0]});
    }
    ll answer = 1e9;
    vi dist = dijkstra(G, s, n);
    for(auto mid = 1; mid <= n; ++mid){
        vi mdist = dijkstra(G, mid, n);
        ll partans = dist[mid];
        partans += mdist[a];
        partans += mdist[b];
        answer = min(answer, partans);
    }
    return answer;
}