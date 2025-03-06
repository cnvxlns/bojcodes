#include<bits/stdc++.h>

#define Size 405
#define inf 0x3f3f3f3f
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
    //cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

void Solve(){
    int N, K;
    int G[Size][Size];
    for(int i = 1; i <= 400; ++i){
        for(int j = 1; j <= 400; ++j){
            G[i][j] = 0;
        }
    }
    cin >> N >> K;
    loop(K){
        int from, to;
        cin >> from >> to;
        G[from][to] = -1;
        G[to][from] = 1;
    }
    
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                if(G[i][j] == 0 && G[i][k] == G[k][j]){
                    G[i][j] = G[i][k];
                    G[j][i] = G[k][i];
                }
            }
        }
    }

    int query;
    cin >> query;
    loop(query){
        int s, e;
        cin >> s >> e;
        cout << G[s][e] << endl;
    }
}
