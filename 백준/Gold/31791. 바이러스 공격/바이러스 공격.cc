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


void Solve(int t){
    int N, M;
    cin >> N >> M;
    int tg, tb, x, b;
    cin >> tg >> tb >> x >> b;
    vector<string> P(N);
    for(auto &i: P){
        cin >> i;
    }
    vvi dist(N, vi(M, inf));
    vpii viruses;
    REP(i, N){
        REP(j, M){
            if(P[i][j] == '*'){
                viruses.push_back({i, j});
            }
        }
    }
    queue<pii> Q;
    for(const auto &i: viruses){
        Q.push(i);
        dist[i.first][i.second] = 0;
    }
    while(!Q.empty()){
        auto [currow, curcol] = Q.front(); Q.pop();
        for(const auto &[drow, dcol]: dxy){
            auto [newrow, newcol] = pii(currow + drow, curcol + dcol);
            if(newrow < 0 || newrow >= N || newcol < 0 || newcol >= M){
                continue;
            }
            int cost = dist[currow][curcol] + 1;
            if(P[newrow][newcol] == '#'){
                cost += tb;
            }
            if(dist[newrow][newcol] > cost){
                dist[newrow][newcol] = cost;
                Q.push({newrow, newcol});
            }
        }
    }
    vpii ans;
    REP(i, N){
        REP(j, M){
            //cout << dist[i][j] << sp;
            if(dist[i][j] > tg){
                ans.push_back({i + 1, j + 1});    
            }
        }
        //cout << endl;
    }
    if(ans.size() == 0){
        cout << -1 << endl;
    }else{
        for(auto [ansi, ansj]: ans){
            cout << ansi << sp << ansj << endl;
        }
    }
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