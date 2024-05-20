#include<bits/stdc++.h>

#define size 1010
#define inf 0x7f7f7f7f

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;

int N;

vi cache(size);

ll dp(vi arr, int curidx){
    if(curidx == N - 1){
        return 0;
    }
    if(curidx > N){
        return inf;
    }
    ll &ret = cache[curidx];
    if(ret){
        return ret;
    }
    ret = inf;
    for(int i = 1; i <= arr[curidx]; ++i){
        ret = min(ret, 1 + dp(arr, curidx + i));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vi arr(N);
    for(auto &i: arr){
        cin >> i;
    }
    ll ans = dp(arr, 0);
    if (ans >= inf){
        cout << -1;
    }else{
        cout << ans;
    }
    return 0;
}