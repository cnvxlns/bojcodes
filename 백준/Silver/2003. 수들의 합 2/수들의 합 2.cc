#include<bits/stdc++.h>

#define Size 20010
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
    int N, M;
    vi a;
    cin >> N >> M;
    a.assign(N + 1, 0);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for(int i = 2; i <= N; ++i){
        a[i] += a[i - 1];
    }
    int ans = 0;
    for(int i = 0; i <= N; ++i){
        for(int j = i + 1; j <= N; ++j){
            if(a[j] - a[i] == M){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
