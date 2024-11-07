#include<bits/stdc++.h>

#define Size 4040
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "

#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

//const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void Solve();

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Solve();
    return 0;
}

int N;
int H[Size][4];
int cache[Size][4];

int dp(int n, int prev){
    if(n >= N){
        return 0;
    }
    if(cache[n][prev]){
        return cache[n][prev];
    }
    int ans = inf;
    for(int i = 0; i < 3; ++i){
        if(prev == i){
            continue;
        }
        ans = min(ans, dp(n + 1, i) + H[n][i]);
    }
    return cache[n][prev] = ans;
}

void Solve(){
    cin >> N;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> H[i][j];
        }
    }
    cout << dp(0, -1);
}