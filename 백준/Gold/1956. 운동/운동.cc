#include<bits/stdc++.h>

#define Size 402
#define inf 0x3f3f3f3fll
#define endl "\n"
#define sp " "
#define int int64_t
#define loop(M) for(int _ = 0; _ < M; ++_)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

void Solve();

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

void Solve(){
    int V, E;
    int path[Size][Size];
    cin >> V >> E;
    for(int i = 1; i <= V; ++i){
        for(int j = 1; j <= V; ++j){
            path[i][j] = inf;
        }
    }
    loop(E){
        int a, b, c;
        cin >> a >> b >> c;
        path[a][b] = c;
    }
    for(int k = 1; k <= V; ++k){
        for(int i = 1; i <= V; ++i){
            for(int j = 1; j <= V; ++j){
                if(i == j){
                    continue;
                }
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
    int ans = inf;
    for(int i = 1; i <= V; ++i){
        for(int j = 1; j <= V; ++j){
            if(i == j){
                continue;
            }
            if(path[i][j] + path[j][i] < inf){
                ans = min(path[i][j] + path[j][i], ans);
            }
        }
    }
    if(ans < inf){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}