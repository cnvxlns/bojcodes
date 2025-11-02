#include<bits/stdc++.h>

#define int int64_t
#define Size 200032
#define inf 4000000000000000000LL 
#define endl "\n"
#define sp " "


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

vi parent;

void init(int size){
    parent.resize(size + 1);
    iota(parent.begin(), parent.end(), 0);
}

int Find(int a){
    if(a == parent[a]){
        return a;
    }
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b){
        return ;
    }else{
        parent[a] = b;
    }
}

void Solve() {
    int N, M;
    cin >> N >> M;
    vtiii lines;
    while(M--){
        int a, b, c;
        cin >> a >> b >> c;
        lines.push_back({c, a, b});
    }
    // cout << "ok" << endl;
    sort(lines.begin(), lines.end());
    int ans = 0, cnt = 0;
    init(N);
    for(const auto &[val, a, b]: lines){
        if(Find(a) == Find(b)){
            continue;
        }else{
            ans += val;
            cnt++;
            Union(a, b);
        }
        if(cnt == N - 1){
            break;
        }
    }
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