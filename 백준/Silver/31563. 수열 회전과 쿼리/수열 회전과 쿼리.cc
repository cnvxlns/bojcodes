#include<bits/stdc++.h>

#define Size 200
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
    int N, Q;
    int base = 0;
    cin >> N >> Q;
    vi a(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for(int i = 1; i < N; ++i){
        a[i + 1] += a[i];
    }
    loop(Q){
        int query;
        cin >> query;
        if(query == 1){
            int k;
            cin >> k;
            base -= k;
            while(base < 0){
                base += N;
            }
            base %= N;
        }
        if(query == 2){
            int k;
            cin >> k;
            base += k;
            base %= N;
        }
        if(query == 3){
            int l, r;
            cin >> l >> r;
            l += base;
            r += base;
            //cout << base << endl;
            
            if(l > N){
                l %= N;
            }
            if(r > N){
                r %= N;
                //r++;
            }
            //cout << l << sp << r << endl;
            if(l == 0){
                cout << a[r] << endl;
            }else if(l <= r){
                cout << a[r] - a[l - 1] << endl;
            }else{
                cout << a[N] - a[l - 1] + a[r] << endl; 
            }
        }
    }
}
