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

int N;
vi a, pfx, sfx;

void Solve(){
    cin >> N;
    a.resize(N);
    pfx.resize(N);
    sfx.resize(N);
    for(auto &i: a){
        cin >> i;
    }
    int ans = pfx[0] = a[0];
    for(auto i = 1; i < N; ++i){
        pfx[i] = a[i] + max(pfx[i - 1], 0ll);
        ans = max(ans, pfx[i]);
    }
    sfx[N - 1] = a[N - 1];
    for(auto i = N - 2; i >= 0; --i){
        sfx[i] = a[i] + max(sfx[i + 1], 0ll);
    }
    for(auto i = 1; i < N - 1; ++i){
        ans = max(ans, sfx[i + 1] + pfx[i - 1]);
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