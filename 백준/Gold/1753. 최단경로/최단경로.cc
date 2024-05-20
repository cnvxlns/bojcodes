#include<bits/stdc++.h>

#define size 20020
#define inf 0x3f3f3f3f
#define endl "\n"

#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tii = tuple<ll, ll, ll>;

void Solve();
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}

ll V, E, K;
vector<vector<pii>> G(size);
vi visited(size), dist(size);

void dijkstra(){
    fill(dist.begin() + 1, dist.begin() + V + 1, inf);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[K] = 0; visited[K] = 1;
    pq.push({0, K});
    while(!pq.empty()){
        auto [curtime, curnode] = pq.top();
        pq.pop();
        if(dist[curnode] < curtime){
            continue;
        }
        for(auto [nexttime, nextnode]: G[curnode]){
            auto newtime = curtime + nexttime;
            if(dist[nextnode] > newtime){
                dist[nextnode] = newtime;
                pq.push({newtime, nextnode});
            }
        }
    }
}

void Solve(){
    cin >> V >> E >> K;
    loop(E){
        ll u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({w, v});
    }
    dijkstra();
    for(int i = 1; i <= V; ++i){
        if(dist[i] >= inf){
            cout << "INF" << endl;
        }else{
            cout << dist[i] << endl;
        }
    }
    
}