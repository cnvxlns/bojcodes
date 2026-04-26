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

pii dxy[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int N;
int ans;

vi queens;

bool validity(int idx, int y){
    for(auto i = 1; i < idx; ++i){
        if(queens[i] == y || abs(idx - i) == abs(queens[i] - y)){
            return false;
        }
    }
    return true;
}

void dfs(int idx){
    if(idx == N + 1){
        ans++;
        return ;
    }
    for(auto i = 1; i <= N; ++i){
        if(validity(idx, i)){
            queens[idx] = i;
            dfs(idx + 1);
        }
    }
}

void Solve(){
    cin >> N;
    queens.resize(N + 1);
    dfs(1);
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