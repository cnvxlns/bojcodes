#include<bits/stdc++.h>

#define int long long
#define Size 200032
#define inf (int)4e18
#define endl "\n"
#define sp " "


const int mod = 9901;

using namespace std;

using vi = vector<int>;
using vc = vector<char>;
using vvi = vector<vi>;
using vvc = vector<vector<char>>;
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

pii drc[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

vi dp;

void Solve(){
    int N;
    cin >> N;
    dp.assign(N + 1, 0);
    dp[1] = 3;
    dp[2] = 7;
    for(int i = 3; i <= N; ++i){
        dp[i] = dp[i - 2] % mod + (dp[i - 1] * 2) % mod;
        dp[i] %= mod;
    }
    cout << dp[N] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}
