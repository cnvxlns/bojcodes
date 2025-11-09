#include<bits/stdc++.h>

#define int long long
#define Size 200032
#define inf (int)4e18
#define endl "\n"
#define sp " "


const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using pic = pair<int, char>;
using pci = pair<char, int>;
using vpii = vector<pii>;
using vpic = vector<pic>;
using vpci = vector<pci>;
using vtiii = vector<tiii>;

pii operator+(const pii& a, const pii& b) {
    return { a.first + b.first, a.second + b.second };
}
pii operator-(const pii& a, const pii& b) {
    return { a.first - b.first, a.second - b.second };
}

pii dxy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void Solve(){
    int N;
    cin >> N;
    vvi a(N, vi(N, 0));
    for(auto &i: a){
        for(auto &j: i){
            cin >> j;
            if(j == 0){
                j = inf;
            }
        }
    }
    vvi dp(N, vi(1 << N, inf));
    dp[0][1] = 0;
    for(auto status = 0; status < (1 << N); ++status){
        for(auto cur = 0; cur < N; ++cur){
            if(!(status & (1 << cur))) continue;
            if(dp[cur][status] == inf) continue;
            for(auto next = 0; next < N; ++next){
                if(a[cur][next] == inf || (status & (1 << next))){
                    continue;
                }else{
                    dp[next][status | (1 << next)] = min(dp[next][status | (1 << next)], dp[cur][status] + a[cur][next]);
                }
            }
        }
    }
    int ans = inf;
    for(int i = 0; i < N; ++i){
        if(dp[i][(1 << N) - 1] != inf && a[i][0] != inf){
            ans = min(ans, dp[i][(1 << N) - 1] + a[i][0]);
        }
    }

    if (N == 1) ans = 0;
        cout << ans << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}