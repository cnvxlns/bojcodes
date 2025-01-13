#include<bits/stdc++.h>

#define Size 300
#define inf 0x3f3f3f3f
#define endl "\n"
#define sp " "
#define loop(M) for(int _ = 0; _ < M; ++_)


using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void Solve();

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Solve();
    return 0;
}

ll dp[1000010][4];

void Solve(){
    int T, M = 3;
    const int mod = 1e9 + 9;
   
    dp[1][1] = 1;   // 1
    dp[2][2] = 1;   // 2

    dp[3][1] = 1;   //21
    dp[3][2] = 1;   //12
    dp[3][3] = 1;   // 3
    cin >> T;
    loop(T){
        int n;
        cin >> n;
        for(int i = M + 1; i <= n; ++i){
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
            dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
            dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
            //1, 2로 끝난 수에 3붙이기 = i-3을 3으로 끝나지 않게 하는 경우의 수
            //2, 3으로 끝난 수에 1붙이기
            //3, 1로 끝난 수에 2붙이기
        }
        if(M < n){
            M = n;
        }
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % mod << endl;
    }
}
