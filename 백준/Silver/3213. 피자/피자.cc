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
    int N;
    cin >> N;
    vi a(4, 0);
    loop(N){
        string s;
        cin >> s;
        if(s == "1/4"){
            a[1]++;
        }
        if(s == "1/2"){
            a[2]++;
        }
        if(s == "3/4"){
            a[3]++;
        }
    }
    int ans = 0;
    while(a[1] > 0 && a[3] > 0){
        ans++;
        a[1]--;
        a[3]--;
    }
    while(a[1] > 0){
        ans++;
        a[1] -= 2;
        a[2] --;
    }
    if(a[1] < 0){
        a[1] = 0;
    }
    while(a[2] > 1){
        ans++;
        a[2] -= 2;
    }

    cout << ans + a[1] + a[2] + a[3] << endl;
}
