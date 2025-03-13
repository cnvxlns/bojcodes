#include<bits/stdc++.h>

#define Size 10020
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

vi cache(Size);

int dp(const vi &arr, int K){
    if(K < 0){
        return inf;
    }
    if(K == 0){
        return 0;
    }
    if(cache[K] != -1){
        return cache[K];
    }
    for(auto i: arr){
        if(i == K){
            return 1;
        }
    }
    int ret = inf;
    for(int i = 0; i < arr.size(); ++i){
        ret = min(ret, dp(arr, K - arr[i]) + 1);
    }
    return cache[K] = ret;
}

void Solve(){
    int N, K;
    cin >> N >> K;
    vi arr;
    fill(cache.begin(), cache.end(), -1);
    loop(N){
        int t;
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    int t = dp(arr, K);
    if(t >= inf){
        cout << -1 << endl;
    }else{
        cout << t << endl;
    }
}