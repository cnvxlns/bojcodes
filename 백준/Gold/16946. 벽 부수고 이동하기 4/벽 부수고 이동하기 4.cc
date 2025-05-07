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
int N, M;
vector<string> m;
vvi visited;
int id = 1;
vi cache(1002000);

int BFS(int row, int col){
    int ret = 0;
    queue<pii> Q;
    Q.push({row, col});
    visited[row][col] = id;
    while(!Q.empty()){
        auto [currow, curcol] = Q.front();
        Q.pop();
        ret++;
        for(const auto &[dr, dc]: dxy){
            auto [nextrow, nextcol] = make_pair(currow + dr, curcol + dc);
            if(nextrow < 0 || nextrow >= N || nextcol < 0 || nextcol >= M){
                continue;
            }
            if(m[nextrow][nextcol] == '1'){
                continue;
            }
            if(visited[nextrow][nextcol] > 0){
                continue;
            }
            visited[nextrow][nextcol] = id;
            
            Q.push(make_pair(nextrow, nextcol));
        }
    }
    cache[id] = ret;
    id++;
    return ret;
}

void Solve(int t){
    
    cin >> N >> M;
    m.resize(N);
    visited.assign(N, vi(M, 0));
    for(auto &i: m){
        cin >> i;
    }
    vvi ans(N, vi(M, 0));
    REP(i, N){
        REP(j, M){
            if(m[i][j] == '0' && visited[i][j] == 0){
                BFS(i, j);
            }
        }
    }
    // REP(i, N){
    //     REP(j, M){
    //         cout << cache[visited[i][j]];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    REP(i, N){
        REP(j, M){
            if(m[i][j] == '0'){
                cout << 0;
            }else{
                int temp = 1;
                map<int, bool> v;
                for(auto [dr, dc]: dxy){
                    auto [newrow, newcol] = make_pair(dr + i, dc + j);
                    if(newrow < 0 || newrow >= N || newcol < 0 || newcol >= M){
                        continue;
                    }
                    if(v[visited[newrow][newcol]] == 1){
                        continue;
                    }
                    v[visited[newrow][newcol]] = 1;
                    temp += cache[visited[newrow][newcol]];
                }
                cout << temp % 10;
            }
        }
        cout << endl;
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