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

int N, T;
vpii lr;

bool p(int S){
    int msum = 0, Msum = 0;
    for(auto i: lr){
        auto [li, ri] = i;
        if(li > S){
            return 0;
        }
        Msum += min(ri, S);
        msum += li;
    }
    return msum <= T && T <= Msum;
}

void Solve(int t){
    int N, M, R;
    cin >> N >> M >> R;
    vi A(N), B(M);
    for(auto &i: A){
        cin >> i;
    }
    for(auto &i: B){
        cin >> i;
    }
    set<int> width;
    for(const auto &i: A){
        for(const auto &j: A){
            if(i == j){
                continue;
            }
            width.insert(abs(i - j));
        }
    }
    sort(B.begin(), B.end());
    int l = 0, r = 0;
    int ans = -1;
    for(const auto &i: width){
        int lo = 0, hi = M - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(B[mid] * i <= R * 2){
                ans = max(B[mid] * i, ans);
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
    }
    if(ans == -1){
        cout << -1 << endl;
    }else{
        cout << fixed << setprecision(1) << ans * 0.5 << endl;
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

