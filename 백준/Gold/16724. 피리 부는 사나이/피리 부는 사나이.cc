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
using tiii = tuple<int, int, int>;
using pic = pair<int, char>;
using pci = pair<char, int>;    
using vpii = vector<pii>;
using vpic = vector<pic>;
using vpci = vector<pci>;
using vtiii = vector<tiii>;

pii operator+(const pii& a, const pii& b) {
    return {a.first + b.first, a.second + b.second};
}
pii operator-(const pii& a, const pii& b) {
    return {a.first - b.first, a.second - b.second};
}

vi parent;

int Find(int a){
    if(parent[a] == a){
        return a;
    }else{
        return parent[a] = Find(parent[a]);
    }
}

void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b){
        return ;
    }else{
        if(a < b){
            parent[b] = a; 
        }else{
            parent[a] = b;
        }
    }
}

void Solve(int t){
    int N, M;
    cin >> N >> M;
    parent.resize(N * M);
    iota(parent.begin(), parent.end(), 0);
    vector<string> b(N);
    for(auto &i: b){
        cin >> i;
    }
    REP(i, N){
        REP(j, M){
            int cur = i * M + j, next;
            if(b[i][j] == 'U'){
                next = cur - M;
            }
            if(b[i][j] == 'D'){
                next = cur + M;
            }
            if(b[i][j] == 'R'){
                next = cur + 1;
            }
            if(b[i][j] == 'L'){
                next = cur - 1;
            }
            Union(cur, next);
        }
    }
    set<int> cycles;
    REP(i, N * M){
        cycles.insert(Find(i));
    }
    cout << cycles.size() << endl;
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