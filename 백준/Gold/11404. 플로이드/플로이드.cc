#include<bits/stdc++.h>

#define Size 130
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
    int n, m;
    cin >> n;
    cin >> m;
    int arr[Size][Size];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            arr[i][j] = inf;
        }
    }
    loop(m){
        int a, b, c;
        cin >> a >> b >> c;
        if(arr[a][b] > c){
            arr[a][b] = c;
        }
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == j){
                    continue;
                }
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(arr[i][j] >= inf){
                cout << 0 << sp;
            }else{
                cout << arr[i][j] << sp;
            }
        }
        cout << endl;
    }
}