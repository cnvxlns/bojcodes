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
    vvi a(N, vi(N));
    for(auto &i: a){
        for(auto &j: i){
            cin >> j;
        }
    }

    int ans = inf;
    for(int bm = 1; bm < (1 << N) - 1; ++bm){
        int team1 = 0, team2 = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if((bm & (1 << i)) && (bm & (1 << j))){
                    team1 += a[i][j];
                }
                if((bm & (1 << i)) == 0 && (bm & (1 << j)) == 0){
                    team2 += a[i][j];
                }
            }
        }
        ans = min(ans, abs(team1 - team2));
    }
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