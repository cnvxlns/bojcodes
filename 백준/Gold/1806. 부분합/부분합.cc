#include<bits/stdc++.h>

#define Size 1024
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
    //cin >> t;
    loop(t){
        Solve();
    }
    return 0;
}

void Solve(){
    int N, M;
    int ans = inf;
    cin >> N >> M;
    vi arr(N);
    for(auto &i: arr){
        cin >> i;
    }
    int left = 0, right = 0;
    int partSum = arr[0];
    while(left <= right && right < N){
        if(partSum < M){
            partSum += arr[++right];
        }else{
            ans = min(ans, right - left + 1);
            partSum -= arr[left++];
        }
    }
    if(ans == inf){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
}