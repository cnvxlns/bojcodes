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
    int N;
    cin >> N;
    priority_queue<int, vi, greater<int>> pq;
    loop(N){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    int cnt = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cnt += a + b;
        pq.push(a + b);
    }
    cout << cnt << endl;
}