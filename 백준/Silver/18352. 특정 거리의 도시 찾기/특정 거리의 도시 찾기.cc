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

void BFS(const vector<vi> &G, vi &dist, int N, int X){
    vi visited(N + 1);
    fill(visited.begin(), visited.end(), 0);
    queue<int> q;
    q.push(X);
    dist[X] = 0;
    visited[X] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto i: G[cur]){
            if(visited[i]){
                continue;
            }else{
                visited[i] = 1;
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }
}

void Solve(){
    int N, M, K, X;
    int flag = 1;
    cin >> N >> M >> K >> X;
    vector<vi> G(N + 1);
    vi dist(N + 1);
    fill(dist.begin(), dist.end(), 0);
    loop(M){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        //G[y].push_back(x);
    }
    BFS(G, dist, N, X);
    for(int i = 1; i <= N; ++i){
        if(dist[i] == K){
            cout << i << endl;
            flag = 0;
        }
    }
    if(flag){
        cout << -1 << endl;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}