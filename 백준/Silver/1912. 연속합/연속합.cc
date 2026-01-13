#include<bits/stdc++.h>

#define Size 300
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int N;

void Solve(){
    cin >> N;
    vi arr(N);
    vi dp(N);
    for(auto &i: arr){
        cin >> i;
    }
    dp[0] = arr[0];
    ll ret = dp[0];
    for(int i = 1; i < N; ++i){
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        ret = max(ret, dp[i]);
    }
    cout << ret << endl;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}