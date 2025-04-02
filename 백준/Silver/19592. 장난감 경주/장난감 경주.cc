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

void Solve();

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;
    REP(_, t){
        Solve();
    }
    return 0;
}

double mintime;

int N;
double X, Y;
double myspeed;

bool boost(int val){
    return (X - val) / myspeed < mintime - 1;
}

void Solve(){
    cin >> N >> X >> Y;
    double M = -1;
    REP(i, N){
        double t;
        cin >> t;
        if(i < N - 1){
            M = max(M, t);
        }else{
            myspeed = t;
        }
    }
    if(myspeed > M){
        cout << 0 << endl;
        return;
    }
    mintime = X / M;
    int lo = 0, hi = Y;
    int found = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(boost(mid)){
            found = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    if(found > Y){
        found = -1;
    }
    cout << found << endl;
}
