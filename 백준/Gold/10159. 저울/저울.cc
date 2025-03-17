#include<bits/stdc++.h>

#define Size 104
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
    int N, M;
    int comp[Size][Size];
    cin >> N >> M;
    loop(M){
        int a, b;
        cin >> a >> b;
        comp[a][b] = 1;
        comp[b][a] = -1;
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                if(i == j){
                    continue;
                }
                if(comp[i][k] != 0 && comp[i][k] == comp[k][j]){
                    comp[i][j]  = comp[i][k];
                    comp[j][i] = -comp[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        int ans = 0;
        for(int j = 1; j <= N; ++j){
            if(i == j){
                continue;
            }
            ans += abs(comp[i][j]);
        }
        cout << N - ans - 1 << endl;
    }
}