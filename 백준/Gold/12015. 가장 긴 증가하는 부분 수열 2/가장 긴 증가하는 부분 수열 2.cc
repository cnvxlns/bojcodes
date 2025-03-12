#include<bits/stdc++.h>

#define Size 402
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
    vi arr(N);
    for(auto &i: arr){
        cin >> i;
    }
    vi LIS;
    for(auto i: arr){
        if(LIS.empty() || LIS.back() < i){
            LIS.push_back(i);
        }else{
            LIS[lower_bound(LIS.begin(), LIS.end(), i) - LIS.begin()] = i;
        }
    }
    cout << LIS.size() << endl;
}