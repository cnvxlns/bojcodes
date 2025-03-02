#include<bits/stdc++.h>

#define Size 300
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int mstprim(const vector<vector<pii>> G, int N){
    int res = 0;
    vi visited(N + 1);
    fill(visited.begin(), visited.end(), 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [curweight, curnode] = pq.top();
        pq.pop();
        if(visited[curnode]){
            continue;
        }else{
            visited[curnode] = 1;
            res += curweight;
            for(auto [nextweight, nextnode]: G[curnode]){
                if(!visited[nextnode]){
                    pq.push({nextweight, nextnode});
                }
            }
        }
    }
    return res; 
}

void Solve(){
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> G(N + 1);
    loop(M){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({w, b});
        G[b].push_back({w, a});
    }
    cout << mstprim(G, N) << endl;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}