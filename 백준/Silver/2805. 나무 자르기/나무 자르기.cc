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

int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

void Solve();

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    Solve();
    return 0;
}

int N, M;

void Solve(){
    cin >> N >> M;
    vi a(N);
    for(auto &i: a){
        cin >> i;
    }
    int MIN = 0, MAX = 1e9;
    int mid;
    while(MIN <= MAX){
        ll length = 0;
        mid = MIN + MAX; mid /= 2;
        for(auto i: a){
            if(i > mid){
                length += i - mid;
            }
        }
        if(length >= M){
            MIN = mid + 1;
        }else{
            MAX = mid - 1;
        }
    }
    cout << MAX;
}