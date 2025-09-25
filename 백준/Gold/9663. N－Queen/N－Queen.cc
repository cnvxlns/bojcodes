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
using pqi = priority_queue<int>;
using pqig = priority_queue<int, vi, greater<int>>;
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

bool validity(vi& chk, int row, int col){
    REP(i, col){
        if(chk[i] == row || abs(chk[i] - row) == abs(i - col)){
            return false;
        }
    }
    return true;
}

void dfs(vi& chk, int col, int& ans){
    if(col == N){
        ans++;
    }
    REP(i, N){
        if(validity(chk, i, col)){
            chk[col] = i;
            dfs(chk, col + 1, ans);
        }
    }
}

void Solve() {
    cin >> N;
    int ans = 0;
    vi chk(N, 0);
    dfs(chk, 0, ans);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}