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
    int K, N;
    cin >> K >> N;
    vi A(N), D(K);
    for(auto &i: A){
        cin >> i;
    }
    sort(A.begin(), A.end());
    for(auto &i: D){
        cin >> i;
    }
    int pfx = 0, cnt = 0, ans = 0;
    for(int i = 0; i < K; ++i){
        pfx += !D[i];
        if(D[i]){
            auto lb = lower_bound(A.begin(), A.end(), pfx);
            if(lb != A.end() && A[lb - A.begin()] <= pfx + cnt){
                cnt++;
            }else{
                ans++;
            }
        }
    }
    cout << ans << endl;
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

