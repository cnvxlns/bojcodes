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
double k;

vi dp;
vpii obj;

void Solve(){
    while(true){
        cin >> N >> k;
        if(N == 0){
            break;
        }
        K = (int)(k * 100 + 0.5);
        obj.resize(N);
        dp.assign(K + 1, 0);
        for(auto &[v, w]: obj){
            double W;
            cin >> v >> W;
            w = (int)(W * 100 + 0.5);
        }
        for(auto i = 1; i <= K; ++i){
            //dp[i] = -inf;
            for(const auto &[v, w]: obj){
                if(i < w){
                    continue;
                }
                dp[i] = max(dp[i - w] + v, dp[i]);
            }
        }
        cout << dp[K] << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}