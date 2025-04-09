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

vi parent(Size), rsize(Size);

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
    }
    if(rsize[a] < rsize[b]){
        parent[b] = a;
        rsize[a] += rsize[b];
    }else{
        parent[a] = b;
        rsize[b] += rsize[a];
    }
}

void Solve(int t___){
    int N;
    cin >> N;
    int cnt = 0;
    unordered_map<string, int> m;
    for(int i = 0; i < Size; ++i){
        parent[i] = i;
        rsize[i] = 1;
    }
    REP(i, N){
        string a, b;
        cin >> a >> b;
        if(m.find(a) == m.end()){
            m[a] = cnt++;
        }
        if(m.find(b) == m.end()){
            m[b] = cnt++;
        }
        Union(m[a], m[b]);
        cout << rsize[Find(m[a])] << endl;
    }
    //cout << endl;
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;
    rep(i, 1, t){
        Solve(i);
    }
    return 0;
}