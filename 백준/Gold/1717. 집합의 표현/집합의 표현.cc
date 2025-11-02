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

int Find(int a){
    if(a == parent[a]){ 
        return a;
    }else{
        return parent[a] = Find(parent[a]);
    }
}

void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b){
        return;
    }else if(a < b){
        parent[b] = a; 
    }else{
        parent[a] = b;
    }
}

void init(int size){
    parent.assign(size + 1, 0);
    iota(parent.begin(), parent.end(), 0);
}


void Solve() {
    int n, m;
    cin >> n >> m;

    init(n);

    while(m--){
        int query, a, b;
        cin >> query >> a >> b;
        if(query == 0){
            Union(a, b);
        }   
        if(query == 1){
            if(Find(a) == Find(b)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }



}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--)
        Solve();
    return 0;
}