#include<bits/stdc++.h>

#define Size 100021
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

void Solve(){
    int N, M;
    cin >> N >> M;
    vi a(N + 1), pfx(N + 1), dp(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    pfx[1] = a[1];
    for(int i = 2; i <= N; ++i){
        pfx[i] = pfx[i - 1] + a[i];
    }
    dp[M] = pfx[M];
    for(int i = M + 1; i <= N; ++i){
        dp[i] = max(dp[i - 1] + a[i], pfx[i] - pfx[i - M]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}