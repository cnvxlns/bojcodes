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

int dp(int N, int len, int visited, int prev){

}

void Solve(int t){
    int N, L;
    cin >> N >> L;
    for(auto i = L; i <= 100; ++i){
        auto a = 2 * N - i * (i - 1);
        if(a < 0){ 
            break;
        }else if(a % (2 * i) != 0){
            continue;
        }else{
            a /= (2 * i);
            for(auto j = 0; j < i; ++j){
                cout << a + j << sp;
            }
            return ;
        }
    }
    cout << -1 << endl;
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