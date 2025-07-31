#include<bits/stdc++.h>

#define Size 200032
#define inf 1e9
#define linf 4e18
#define endl "\n"
#define sp " "
#define int int64_t
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using qi = queue<int>;
using si = stack<int>;
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
    }
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b){
        return;
    }
    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}

void Solve(int t){
    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);
    iota(parent.begin(), parent.end(), 0);
    vtiii r(M);
    for(auto &[a, b, c]: r){
        cin >> a >> b >> c;
    }
    sort(r.begin(), r.end(), 
    [](tiii a, tiii b){
        return get<2>(a) < get<2>(b);
    });
    int ans = 0, MAX = -1;
    for(const auto &[a, b, c]: r){
        if(Find(a) != Find(b)){
            Union(a, b);
            ans += c;
            MAX = max(MAX, c);
        }
    }
    cout << ans - MAX << endl;
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