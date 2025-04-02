#include<bits/stdc++.h>

#define Size 130
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
using tiii = tuple<int, int, int>;
using vpii = vector<pii>;
using vtiii = vector<tiii>;

void Solve(int t){
    int X = t;
    cin >> X;
    int lo = 0, hi = 1e10;
    int floor;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(mid*(mid + 1) / 2 < X){
            lo = mid + 1;
        }else{
            hi = mid;
        }
        floor = lo + 1;
    }
    if(floor % 2 == 1)
        cout << X - lo * (lo - 1) / 2 << "/" << floor - (X - lo * (lo - 1) / 2) << endl;
    else{
        cout << floor - (X - lo * (lo - 1) / 2) << "/" << X - lo * (lo - 1) / 2  << endl;
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

