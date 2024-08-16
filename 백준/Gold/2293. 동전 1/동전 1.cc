#include<bits/stdc++.h>

#define Size 20020
#define inf 0x3f3f3f3f
#define endl "\n"

#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void Solve();

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}

void Solve(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N), cache(K + 1);
    cache[0] = 1;
    for(auto& i: a){
        cin >> i;
    }
    for(int i = 0; i < N; ++i){
        for(int j = a[i]; j <= K; ++j){
            cache[j] += cache[j - a[i]];
        }
    }
    cout << cache[K];
}
