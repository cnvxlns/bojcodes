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
using pqi = priority_queue<int>;
using pqig = priority_queue<int, vi, greater<int>>;
using tiii = tuple<int, int, int>;
using tiiii = tuple<int, int, int, int>;
using pic = pair<int, char>;
using pci = pair<char, int>;
using vpii = vector<pii>;
using vpic = vector<pic>;
using vpci = vector<pci>;
using vtiii = vector<tiii>;
using vtiiii = vector<tiiii>;

pii operator+(const pii& a, const pii& b) {
    return { a.first + b.first, a.second + b.second };
}
pii operator-(const pii& a, const pii& b) {
    return { a.first - b.first, a.second - b.second };
}

inline tiiii identity_node(){ return {-(1LL<<60), -(1LL<<60), 0, -(1LL<<60)}; }

int base;
vtiiii segtree; //lmax, rmax, sum, best

tiiii merge(tiiii l, tiiii r){
    auto &[lmaxl, rmaxl, suml, bestl] = l;
    auto &[lmaxr, rmaxr, sumr, bestr] = r;
    tiiii ret;
    auto &[lmax, rmax, sum, best] = ret;
    lmax = max(lmaxl, suml + lmaxr);
    rmax = max(rmaxr, rmaxl + sumr);
    best = max(rmaxl + lmaxr, max(bestl, bestr));
    sum = suml + sumr;
    return ret;
}

void init(vi &a, int N){
    for(base = 1; base <= N; base *= 2);
    segtree.resize(base * 2);
    for(auto i = N; i < base; ++i){
        a.push_back(0);
    }
    // for(auto i: a){
    //     cout << i << sp;
    // }
    for(auto i = 0; i < a.size(); ++i){
        int lmax, rmax, sum, best;
        // lmax = rmax = best = max(0ll, a[i]);
        lmax = rmax = best = a[i];
        sum = a[i];
        segtree[i + base] = {lmax, rmax, sum, best};
    }
    for(int i = base - 1; i > 0; --i){
        segtree[i] = merge(segtree[i * 2], segtree[i * 2 + 1]);
    }
}

int query(int lo, int hi){
    lo += base - 1; hi += base -1 ;
    tiiii L = identity_node(), R = identity_node();
    while(lo <= hi){
        if(lo & 1){ 
            L = merge(L, segtree[lo]); ++lo;
        }
        if(!(hi & 1)){ 
            R = merge(segtree[hi], R); 
            --hi; 
        }
        lo /= 2;
        hi /= 2;
    }
    tiiii ret = merge(L, R);  
    return get<3>(ret);
}

void Solve() {
    int N;
    cin >> N;
    vi a(N);
    for(auto &i : a){
        cin >> i;
    }
    init(a, N);
    // int idx = 1;
    // for(int i = 1; i < base * 2; ++i){
    //     auto &[a, b, c, d] = segtree[i];
    //     cout << i << ": [" << a << sp << b << sp << c << sp << d << "] ";
    //     if(idx == 1 || idx == 2 || idx == 4 || idx == 8 || idx == 16){
    //         cout << endl;
    //     }
    //     idx++;
    // }
    int q;
    cin >> q;
    while(q--){
        int left, right;
        cin >> left >> right;
        cout << query(left, right) << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    REP(i, t){
        Solve();
    }
    return 0;
}