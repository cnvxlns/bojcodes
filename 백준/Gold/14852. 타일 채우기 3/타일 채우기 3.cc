#include<bits/stdc++.h>

#define Size 402
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
    int N;
    cin >> N;
    vi dp(N + 1), pfx(N + 1);
    dp[0] = 1;
    dp[1] = 2;
    pfx[0] = 1;
    pfx[1] = 3;
    for(int i = 2; i <= N; ++i){
        dp[i] = (2ll * pfx[i - 1]) % MOD + dp[i - 2] % MOD;
        dp[i] %= MOD;
        pfx[i] = pfx[i - 1] + dp[i];
        pfx[i] %= MOD;
    }
    cout << dp[N] << endl;
}