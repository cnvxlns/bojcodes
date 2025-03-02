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

int N, M;

void BFS(const vector<vi> &G, vi &visited, int start, vi &ans){
    int order = 1;
    queue<int> Q;
    Q.push(start);
    visited[start] = 1;
    ans[start] = order++;
    while(!Q.empty()){
        ll cur = Q.front();
        Q.pop();
        for(auto next: G[cur]){
            if(visited[next]){
                continue;
            }else{
                Q.push(next);
                ans[next] = order++;
                visited[next] = 1;
            }
        }
    }
}

void Solve(){
    int N, M, R;
    cin >> N >> M >> R;
    vector<vi> G(N + 1);
    vi visited(N + 1);
    vi ans(N + 1);
    loop(M){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(auto i = 1; i <= N; ++i){
        sort(G[i].begin(), G[i].end());
    }
    fill(visited.begin(), visited.end(), 0);
    fill(ans.begin(), ans.end(), 0);
    BFS(G, visited, R, ans);
    for(int i = 1; i <= N; ++i){
        cout << ans[i] << endl;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}