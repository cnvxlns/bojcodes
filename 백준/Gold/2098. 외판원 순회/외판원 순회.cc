#include<bits/stdc++.h>

#define Size 20
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
    // cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

int N;
int cost[Size][Size];
vector<vi> cache;

int TSP(int cur, int visited){
    if(visited == (1 << N) - 1){
        if(cost[cur][0]){
            return cost[cur][0];
        }else{
            return inf;
        }
    }
    int &ret = cache[cur][visited];
    if(ret != -1){
        return ret;
    }
    ret = inf;
    for(int i = 0; i < N; ++i){
        if((visited & (1 << i)) == 0 && cost[cur][i] != 0){
            ret = min(ret, cost[cur][i] + TSP(i, visited | (1 << i)));
        }
    }
    return ret;
}

void Solve(){
    cin >> N;
    cache.assign(N, vi(1 << N, -1));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> cost[i][j];
        }
    }
    cout << TSP(0, 1) << endl;
}