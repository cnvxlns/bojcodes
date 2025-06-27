#include<bits/stdc++.h>

#define Size 200032
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)

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
    return {a.first + b.first, a.second + b.second};
}
pii operator-(const pii& a, const pii& b) {
    return {a.first - b.first, a.second - b.second};
}

void Solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vvi grid(2, vi(n));\
    vi isprime(200'100);
    fill(isprime.begin(), isprime.end(), 1);
    for(auto i = 2; i <= 200020; ++i){
        if(isprime[i] == 1){
            for(auto j = 2; i * j <= 200020; ++j){
                isprime[i * j] = 0;
            }
        }
    }
    for(auto i = 0; i < 2; ++i){
        for(auto &j: grid[i]){
            cin >> j;
        }
    }
    vi dp(n + 1, 0);
    dp[1] = isprime[grid[0][0] + grid[1][0]] ? a : b;
    for(auto i = 2; i <= n; ++i){
        auto ver = grid[0][i - 1] + grid[1][i - 1];
        auto hor0 = grid[0][i - 2] + grid[0][i - 1];
        auto hor1 = grid[1][i - 2] + grid[1][i - 1];
        dp[i] = max(dp[i - 1] + (isprime[ver] ? a : b), dp[i - 2] + (isprime[hor0] ? a : b) + (isprime[hor1] ? a : b)); 
    }
    cout << dp[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
