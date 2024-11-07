#include<bits/stdc++.h>

#define Size 404
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "

#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void Solve();

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Solve();
    return 0;
}

vector<string> G(Size);
vi valpha(30);

int R, C, ans;

void dfs(int row, int col, int depth){
    ans = max(ans, depth);
    //cout << row << " " << col << endl;
    for(auto i: dij){
        int newrow = row + i.first, newcol = col + i.second;
        if(newrow < 0 || newcol < 0 || newrow >= R || newcol >= C){
            continue;
        }
        if(valpha[G[newrow][newcol] - 65]){
            continue;
        }
        valpha[G[newrow][newcol] - 65] = 1;
        dfs(newrow, newcol, depth + 1);
        valpha[G[newrow][newcol] - 65] = 0;
    }
}

void Solve(){
    cin >> R >> C;
    for(int i = 0; i < R; ++i){
        cin >> G[i];
    }
    valpha[G[0][0] - 65] = 1;
    dfs(0, 0, 1);
    cout << ans;
}