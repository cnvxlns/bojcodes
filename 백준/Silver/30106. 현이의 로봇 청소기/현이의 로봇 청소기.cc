#include<bits/stdc++.h>

#define Size 200032
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
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
    int N, M, K;
    cin >> N >> M >> K;
    vvi a(N, vi(M, 0));
    for(auto i = 0; i < N; ++i){
        for(auto j = 0; j < M; ++j){
            cin >> a[i][j];
        }
    }
    queue<pii> Q;
    vvi visited(N, vi(M, 0));
    int ans = 0;
    for(auto i = 0; i < N; ++i){
        for(auto j = 0; j < M; ++j){
            if(visited[i][j]){
                continue;
            }
            ans++;
            Q.push({i, j});
            while(!Q.empty()){
                pii cur = Q.front();
                Q.pop();
                auto [curr, curc] = cur;
                visited[curr][curc] = 1;
                for(auto d: dxy){
                    auto [newr, newc] = cur + d;
                    if(newr < 0 || newc < 0 || newr >= N || newc >= M || visited[newr][newc]){
                        continue;
                    }else{
                        if(abs(a[curr][curc] - a[newr][newc]) <= K){
                            visited[newr][newc] = 1;
                            Q.push({newr, newc});
                        }
                    }
                }
            }
        }
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