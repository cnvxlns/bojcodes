#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvi = vector<vi>;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vpii> G(N + 1);
    for(const auto& r : road) {
        auto a = r[0], b = r[1], w = r[2];
        G[a].push_back({w, b});
        G[b].push_back({w, a});
    }
    priority_queue<pii, vpii, greater<pii>> pq;
    vi dist(N + 1, 1e9);
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        auto [curdist, curnode] = pq.top(); pq.pop();
        if(curdist > dist[curnode]){
            continue;
        }
        for(auto [nextdist, nextnode]: G[curnode]){
            auto newdist = curdist + nextdist;
            if(newdist < dist[nextnode]){
                dist[nextnode] = newdist;
                pq.push({newdist, nextnode});
            }
        }
    }
    for(const auto &d: dist){
        if(d <= K){
            answer++;
        }
    }
    return answer;
}