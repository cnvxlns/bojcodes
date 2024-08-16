#include<bits/stdc++.h>

#define Size 20020
#define inf 0x3f3f3f3f
#define endl "\n"

#define loop(M) for(int _ = 0; _ < M; ++_)

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using tiii = tuple<ll, ll, ll>;

const vector<pii> dij = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void Solve();

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}

void Solve(){
    int N;
    cin >> N;
    vector<bool> cache(N + 1);
    cache[1] = cache[3] = cache[4] = cache[5] = 1;
    cache[2] = 0; 
    for(int i = 6; i <= N; ++i){
        if(!(cache[i - 1]  && cache[i - 3]  && cache[i - 4])){
            cache[i] = 1;
        }else{
            cache[i] = 0;
        }
    }
    if(cache[N]){
        cout << "SK";
    }else{
        cout << "CY";
    }
}
