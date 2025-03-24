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

int N, M, K;
vpii arr;

bool maxbeer(int x){
    int ret = 0;
    int cnt = 0;
    for(const auto &[v, c]: arr){
        if(c <= x){
            ret += v;
            cnt++;
        }
        if(cnt == N){
            break;
        }
    }
    if(ret >= M && cnt == N){
        return 1;
    }else{
        return 0;
    }
}

bool cmp(pii a, pii b){
    return a.first > b.first;
}

void Solve(){
    cin >> N >> M >> K;    
    arr.resize(K);
    for(auto &[v, c]: arr){
        cin >> v >> c;
    }
    sort(arr.begin(), arr.end(), cmp);
    int lo = 1ll, hi = 1ll << 32 - 1ll;
    int ans = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(maxbeer(mid)){
            hi = mid - 1;
            ans = mid;
        }else{
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}
