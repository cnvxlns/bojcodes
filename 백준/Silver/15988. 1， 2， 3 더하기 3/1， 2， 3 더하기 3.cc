#include<bits/stdc++.h>

#define Size 2002
#define inf 0x3f3f3f3f
#define endl "\n"

#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using vc = vector<char>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;
using pqi = priority_queue<ll>;

//const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void Solve();

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}

vi cache(1002000);

ll dp(int N){
    const int mod = 1e9+9;
    if(N == 1){
        return 1;
    }
    if(N == 2){
        return 2;
    }
    if(N == 3){
        return 4;
    }
    if(cache[N]){
        return cache[N];
    }
    return cache[N] = (dp(N - 1) % mod + dp(N - 2) % mod + dp(N - 3) % mod) % mod;
}


void Solve(){
    int T;
    cin >> T;
    loop(T){
        int N;
        cin >> N;
        cout << dp(N) << endl;
    }
}
