#include<bits/stdc++.h>

#define int int64_t
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

int N, K;

vvi dp;
vpii obj;

// int dp(int idx, int W){
//     if(idx >= N){
//         return 0;
//     }
//     if(W > K){
//         return -inf;
//     }
//     int &ret = cache[idx][W];
//     if(ret != 0){
//         return ret;
//     }
//     const auto &[w, v] = obj[idx];
//     return ret = max(dp(idx + 1, W), dp(idx + 1, W + w) + v);
// }

void Solve(){
    cin >> N >> K;
    dp.assign(N, vi(K + 1, 0));
    obj.resize(N);
    for(auto &[w, v]: obj){
        cin >> w >> v;
    }
    for(auto j = 1; j <= K; ++j){
        auto [w, v] = obj[0];
        if(j < w){
            dp[0][j] = 0;
        }else{
            dp[0][j] = v;
        }
    }
    for(auto i = 1; i < N; ++i){
        for(auto j = 1; j <= K; ++j){
            auto [w, v] = obj[i];
            if(j < w){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
            }
        }
    }


    cout << dp[N - 1][K] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}