#include<bits/stdc++.h>

#define inf 0x3f3f3f3f
#define endl "\n"

#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

void Solve();
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}

vector<tiii> edges;
vi dist;

bool bellmanford(int start, int V, int E){
    dist[start] = 0;
    for (int i = 0; i < V; i++) {
        for (auto edge: edges) {
            auto [u, v, w] = edge;
            if (dist[u] != inf && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (i == V - 1) {
                    return true; 
                }
            }
        }
    }
    return false;
}

void Solve(){
    int N, M;
    cin >> N >> M;
    dist.assign(N + 1, inf);
    for(int i = 0 ; i < M; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    if(bellmanford(1, N, M)){
        cout << -1 << endl;
    }else{
        for(auto i = 2; i <= N; ++i){
            if(dist[i] != inf)
            cout << dist[i] << endl;
            else{
                cout << -1 << endl;
            }
        }
    }
    
}