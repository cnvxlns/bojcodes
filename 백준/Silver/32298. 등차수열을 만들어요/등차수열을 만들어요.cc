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
    int N, M;
    vi isprime;
    isprime.assign(Size, 1);
    isprime[1] = 0;
    isprime[2] = 1;
    for(int i = 3; i <= 2000000; ++i){
        for(int j = 2; i * j <= 2000000; ++j){
            isprime[i * j] = 0;
        }
    }
    cin >> N >> M;
    for(int i = 1; i <= 2000000; ++i){
        vi ans;
        int flag = 0;
        for(int j = 0; j < N; ++j){
            int t = i + j * M;
            if(t > 2000000 || isprime[t]){
                flag = 1;
            }
            ans.push_back(t);
        }
        if(flag){
            continue;
        }
        for(auto i: ans){
            cout << i << sp;
        }
        break;
    }
}
