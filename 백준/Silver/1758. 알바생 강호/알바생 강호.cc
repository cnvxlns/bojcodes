#include<bits/stdc++.h>

#define Size 20400
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
using vpii = vector<pii>;

void Solve();

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

void Solve(){
    int N;
    cin >> N;
    vi a(N);
    for(auto &i :a){
        cin >> i;
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < N; ++i){
        if(a[i] > i){
            ans += a[i] - i;
        }
    }
    cout << ans << endl;
}