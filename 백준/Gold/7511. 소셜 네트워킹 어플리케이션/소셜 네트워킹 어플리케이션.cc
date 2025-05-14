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
using vtiii = vector<tiii>;
using pic = pair<int, char>;
using pci = pair<char, int>;
using vpii = vector<pii>;
using vpic = vector<pic>;
using vpci = vector<pci>;
using vvpii = vector<vpii>;

pii operator+(const pii& a, const pii& b) {
    return {a.first + b.first, a.second + b.second};
}
pii operator-(const pii& a, const pii& b) {
    return {a.first - b.first, a.second - b.second};
}

pii dxy[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vi parent;

int Find(int a){
    if(a == parent[a]){
        return a;
    }
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b){
        return;
    }
    parent[a] = b;
}

void Solve(int t___){
    int n, k, m;
    cin >> n >> k;
    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);
    REP(i, k){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    cin >> m;
    REP(i, m){
        int a, b;
        cin >> a >> b;
        cout << static_cast<int> (Find(a) == Find(b)) << endl;
    }
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;
    rep(i, 1, t){
        cout << "Scenario " << i << ":" << endl;
        Solve(i);
        cout << endl;
    }
    return 0;
}