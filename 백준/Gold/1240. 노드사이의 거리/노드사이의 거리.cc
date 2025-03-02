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
vi visited(1010);

void dist(const vector<vector<pii>> &T, int x, int y, int ans){
    if(x == y){
        cout << ans << endl;
        return ;
    }
    for(auto [w, next]: T[x]){
        if(visited[next]){
            continue;
        }else{
            visited[next] = 1;
            dist(T, next, y, ans + w);
        }
    }
}

void Solve(){
    cin >> N >> M;
    vector<vector<pii>> T(N + 1);
    loop(N - 1){
        int x, y, w;
        cin >> x >> y >> w;
        T[x].push_back({w, y});
        T[y].push_back({w, x});
    }
    loop(M){
        int x, y;
        cin >> x >> y;
        fill(visited.begin(), visited.end(), 0);
        visited[x] = 1;
        dist(T, x, y, 0);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}