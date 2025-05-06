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
using pic = pair<int, char>;
using pci = pair<char, int>;
using vpii = vector<pii>;
using vpic = vector<pic>;

pii operator+(const pii& a, const pii& b) {
    return {a.first + b.first, a.second + b.second};
}
pii operator-(const pii& a, const pii& b) {
    return {a.first - b.first, a.second - b.second};
}

pii dxy[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


void Solve(int t___){
    int N;
    cin >> N;
    vi a(N);
    vi era(1010);
    fill(era.begin(), era.end(), 0);
    era[1] = 1;
    for(auto &i: a){
        cin >> i;
    }
    rep(i, 2, 1000){
        if(era[i] == 1){
            continue;
        }
        for(int j = 2; i * j <= 1000; ++j){
            era[i * j] = 1;
        }
    }
    // rep(i, 1, 100){
    //     cout << era[i] << endl;
    // }
    int ans = 0;
    for(const auto &i: a){
        ans += !era[i];
    }
    cout << ans << endl;
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    rep(i, 1, t){
        Solve(i);
    }
    return 0;
}