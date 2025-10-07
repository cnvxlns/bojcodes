#include<bits/stdc++.h>

#define Size 200032
#define inf 4e18
#define endl "\n"
#define sp " "
#define int int64_t

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
vvi a;
vi l(20, 0), r(20, 0), ans(2, 0);

void dfs(int row, int col, int cnt, int color){
    if (col >= N) {
        row++;
        if(col % 2 == 0){
            col = 1;
        }else{
            col = 0;
        }
    }
    if (row >= N) {
        ans[color] = max(ans[color], cnt);
        return ;
    }
 
    if (a[row][col] && !l[col - row + N - 1] && !r[row + col]){
        l[col - row + N - 1] = r[row + col] = 1;
        dfs(row, col + 2, cnt + 1, color);
        l[col - row + N - 1] = r[row + col] = 0;
    }
    dfs(row, col + 2, cnt, color);
}

void Solve() {
    cin >> N;
    a.assign(N, vi(N));
    for(auto i = 0; i < N; ++i){
        for(auto j = 0; j < N; ++j){
            cin >> a[i][j];
        }
    }
    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);
    cout << ans[0] + ans[1];
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}