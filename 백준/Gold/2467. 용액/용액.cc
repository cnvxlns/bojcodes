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

void Solve(int t){
    int N;
    cin >> N;
    vi a(N);
    for(auto &i :a){
        cin >> i;
    }
    int lo = 0, hi = N - 1;
    int sum = linf;
    pii ans;
    while(lo < hi){
        if(sum > abs(a[lo] + a[hi])){
            ans = {a[lo], a[hi]};
            sum = abs(a[lo] + a[hi]);
        }
        if(a[lo] + a[hi] < 0){
            lo++;
        }else{
            hi--;
        }
    }
    cout << ans.first << sp << ans.second << endl;
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