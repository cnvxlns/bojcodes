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

vvvi cache;

int dp(int used, int len, int lastdigit){
    if(len == 0){
        if(used != 1023 || lastdigit ==0){
            return 0;
        }else{
            return 1;
        }
    }
    int &ret = cache[used][len][lastdigit];
    if(ret != -1){
        return ret;
    }else{
        ret = 0;
        if (lastdigit > 0){
            ret += dp(used | (1 << (lastdigit - 1)), len - 1, lastdigit - 1) % (int)1e9;
            ret %= (int)1e9;
        }
        if (lastdigit < 9){
            ret += dp(used | (1 << (lastdigit + 1)), len - 1, lastdigit + 1) % (int)1e9;
            ret %= (int)1e9;
        }
    }
    return ret;
}

void Solve(int t){
    int N;
    cin >> N;
    cache.assign(1024, vvi(102, vi(10, -1)));
    int ans = 0;
    rep(i, 0, 9){
        ans += dp(1 << i, N - 1, i) % (int)1e9;
        ans %= (int)1e9;
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