#include<bits/stdc++.h>

#define Size 2000010
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define int int64_t
#define loop(M) for(int _ = 0; _ < M; ++_)

const int MOD = 1e9 + 7;

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

void Solve();

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

void Solve(){
    int N, K;
    cin >> N >> K;
    int lo = 0, hi = N / 2;
    int row, pieces;
    while(lo <= hi){
        row = (lo + hi) / 2;
        pieces = (row + 1) * (N - row + 1);
        if(K == pieces){
            cout << "YES" << endl;
            return;
        }else if(K < pieces){
            hi = row - 1;
        }else{
            lo = row + 1;
        }
    }
    cout << "NO" << endl;

}